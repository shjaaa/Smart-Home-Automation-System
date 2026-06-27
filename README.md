# 🏠 Smart Home Automation System using Arduino

A Smart Home Automation System built using **Arduino Uno** and simulated on **Tinkercad**. This project integrates multiple sensors and actuators to automate home safety and monitoring functions such as motion detection, gas leak detection, temperature monitoring, and water level management.

---

## 📌 Features

### 🚶 Motion Detection

* Uses a **PIR Sensor** to detect human motion.
* Automatically turns on the light (LED/Bulb).
* Activates the buzzer for alerts.

### 🔥 Temperature Monitoring

* Uses a **TMP36 Temperature Sensor**.
* Continuously monitors room temperature.
* Triggers an alert if the temperature exceeds the threshold.

### 🧪 Gas Leak Detection

* Simulated using a **Potentiometer** (or Gas Sensor if available).
* Activates the buzzer when gas concentration crosses the set threshold.

### 💧 Water Level Monitoring

* Uses an **Ultrasonic (PING))) Sensor**.
* Automatically controls the motor:

  * Tank Empty → Motor ON
  * Tank Full → Motor OFF

### 🔔 Alarm System

* A buzzer is activated during:

  * Motion detection
  * Gas leakage
  * High temperature conditions

---

## 🛠️ Components Used

| Component                             | Quantity |
| ------------------------------------- | -------- |
| Arduino Uno                           | 1        |
| PIR Motion Sensor                     | 1        |
| TMP36 Temperature Sensor              | 1        |
| Potentiometer (Gas Sensor Simulation) | 1        |
| Ultrasonic PING))) Sensor             | 1        |
| Buzzer                                | 1        |
| LED/Bulb                              | 1        |
| DC Motor/Relay Module                 | 1        |
| Breadboard                            | 2        |
| Jumper Wires                          | Multiple |

---

## ⚙️ Working Principle

1. The PIR sensor detects movement and switches on the light.
2. The potentiometer simulates gas concentration and triggers an alarm when the threshold is exceeded.
3. The TMP36 continuously monitors temperature and activates an alert for high temperatures.
4. The ultrasonic sensor measures water level and automatically controls the motor.
5. Sensor readings are displayed in the Serial Monitor for real-time monitoring.

---

## 📊 Serial Monitor Output Example

```text
Motion Detected -> Bulb ON
GAS LEAK DETECTED!
HIGH TEMPERATURE: 42.5
Water LOW -> Motor ON

Gas: 650 | Temp: 42.5 | Water: 23.6
```

---

## 🖥️ Circuit Simulation

The complete circuit was designed and tested using **Tinkercad Circuits**.

---

## 🚀 Future Improvements

* Integration with IoT platforms (Blynk, ThingSpeak, MQTT).
* Mobile application for remote monitoring.
* Automatic notifications via Email or SMS.
* Cloud data logging and analytics.
* Voice assistant integration (Alexa/Google Assistant).

---

## 📚 Learning Outcomes

* Arduino programming in Embedded C/C++
* Sensor interfacing and analog/digital I/O
* Automation logic and control systems
* Circuit simulation using Tinkercad
* Debugging hardware and software integration

---

## 👨‍💻 Author

**Shobhit Singh**
Electronics and Communication Engineering (ECE)
Jaypee Institute of Information Technology

---

⭐ If you found this project useful, consider giving the repository a star!
