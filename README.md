# Resource-Constrained Implementations of AI Algorithms

This repository contains the work done as part of **Practice School-I** at **CSIR-CEERI, Pilani** under the **Birla Institute of Technology & Science (BITS) Pilani**.  
The project explores **Tiny Machine Learning (TinyML)** and the deployment of **AI algorithms** on **resource-constrained devices**, focusing on **Human Activity Recognition (HAR)** using **Arduino Nano 33 BLE Sense** and **TensorFlow Lite**.

---

## Project Overview
Deploying AI algorithms in low-power, resource-constrained environments poses unique challenges. This project demonstrates the feasibility of implementing **real-time Human Activity Recognition (HAR)** on microcontrollers while maintaining efficiency in terms of:
- Accuracy
- Latency
- Memory footprint
- Power consumption

Key contributions include:
- Implementation of a **1D Convolutional Neural Network (CNN)** for HAR.
- Model optimization via **quantization** and **pruning**.
- Deployment on **Arduino Nano 33 BLE Sense** with **TensorFlow Lite Micro**.
- Real-time inference using built-in **accelerometer and IMU sensors**.

---

## Features
- Human Activity Recognition (HAR): Walking, jogging, sitting, standing, climbing upstairs, and downstairs.
- TinyML on Edge Devices: Optimized models under 1 MB for deployment on microcontrollers.
- Real-Time Processing: Live sensor data classification via Arduino IMU.
- Accuracy: Achieved ~92–94% on the WISDM dataset.
- Compact Model: Final TensorFlow Lite model ~600 KB.

---

## Repository Structure
```
├── data/                  # Preprocessed WISDM dataset
├── notebooks/             # Model training and experimentation in Python
├── models/                # Saved models (TensorFlow & TFLite formats)
├── arduino/               # Arduino IDE sketches for deployment
│   ├── model.h            # Converted TFLite model in C array format
│   └── main.ino           # Arduino code for sensor data collection & inference
├── results/               # Accuracy, confusion matrices, plots
└── README.md              # Project documentation
```

---

## Implementation Steps
1. **Model Training (Python, TensorFlow/Keras)**  
   Train a **1D CNN** on accelerometer data from the WISDM dataset.  
2. **Optimization**  
   Apply quantization and pruning to reduce model size.  
3. **Conversion**  
   Convert to TensorFlow Lite, then to a C-array header file for Arduino IDE.  
4. **Deployment on Arduino Nano 33 BLE Sense**  
   Program sensors and model inference in C++.  
   Display predictions in real-time via serial monitor.  

---

## Results
- Accuracy: ~92–94% on test data.  
- Model Size: ~600 KB (TFLite format).  
- Real-Time Performance: Near-instant predictions using onboard IMU sensors.  
- Power Efficiency: Optimized for low-power wearable/IoT devices.  

---

## References
- Warden, P., & Situnayake, D. (2019). *TinyML: Machine Learning with TensorFlow Lite on Arduino and Ultra-Low-Power Microcontrollers.* O'Reilly Media.  
- [TensorFlow Lite Documentation](https://www.tensorflow.org/lite)  
- [Arduino Nano 33 BLE Sense Documentation](https://docs.arduino.cc/hardware/nano-33-ble-sense)  
- [WISDM Dataset](https://www.cis.fordham.edu/wisdm/)  

---

## Authors
- Rajat Srivastava – 2022B1A81375G  
- Shivam Raj – 2022A8PS0397P  

Supervised by **Dr. Sumeet Saurav** and **Dr. Ravi Saini** (CSIR-CEERI, Pilani)  
Faculty In-Charge: **Dr. Pankaj Arora** and **Dr. Meetha Shenoy**

---

## Future Work
- Integration of multiple sensor modalities (e.g., gyroscope + accelerometer).  
- Exploration of federated learning and on-device incremental learning.  
- Advanced synthetic data generation to improve training robustness.  
- Optimization for other microcontrollers and wearable platforms.  
