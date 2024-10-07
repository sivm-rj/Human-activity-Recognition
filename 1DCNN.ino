// Uncomment the appropriate library definition according to your board version
#include <Arduino_LSM9DS1.h>  // IMU Sensor Library for Arduino Nano 33 BLE Rev.1
// #include <Arduino_BMI270_BMM150.h> // IMU Sensor Library for Arduino Nano 33 BLE Rev.2

#include <ArduTFLite.h>
#include "model.h"

const int numSamples = 80;                      // Number of samples for a single gesture
int samplesRead = 0;                            // Sample counter
const int inputLength = 240;                    // Dimension of input tensor (3 values * 80 samples)
int num = 0;                                    // For reducing the sampling rate
constexpr int tensorArenaSize = 16 * 1024;      // Tensor arena size
alignas(16) byte tensorArena[tensorArenaSize];  // Aligned tensor arena

const char* GESTURES[] = {
  "Downstairs",
  "Jogging",
  "Sitting",
  "Standing",
  "Upstairs",
  "Walking"
};

void setup() {
  Serial.begin(9600);
  while (!Serial)
    ;

  // Initialize IMU sensor
  if (!IMU.begin()) {
    Serial.println("IMU sensor init failed!");
    while (true)
      ;  // Stop program if initialization fails
  }
  // Print IMU sampling frequencies
  Serial.print("Accelerometer sampling frequency = ");
  Serial.print(IMU.accelerationSampleRate());
  Serial.println(" Hz");

  Serial.println();
  Serial.println("Init model...");
  if (!modelInit(model, tensorArena, tensorArenaSize)) {
    Serial.println("Model initialization failed!");
    while (true)
      ;  // Stop program if model initialization fails
  }
  Serial.println("Model initialization done.");
}

void loop() {
  float x, y, z;
  // Check if a sample is available
  if (IMU.accelerationAvailable()) {
    // Read acceleration values
    ++num;
    if (num == 6) {
      IMU.readAcceleration(x, y, z);

      // Store values in the input tensor
      modelSetInput(x, samplesRead * 3 + 0);
      modelSetInput(y, samplesRead * 3 + 1);
      modelSetInput(z, samplesRead * 3 + 2);

      samplesRead++;

      // If all samples are collected, run inference
      if (samplesRead == numSamples) {
        if (!modelRunInference()) {
          Serial.println("RunInference Failed!");
          return;
        }

        // Get and print output values as percentage
        for (int i = 0; i < 6; i++) {
          Serial.print(GESTURES[i]);
          Serial.print(": ");
          Serial.print(modelGetOutput(i) * 100, 2);
          Serial.println("%");
        }
        Serial.println();
        samplesRead = 0;
      }
      num=0;
    }
  }
}