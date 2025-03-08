# Low RPM Wind Turbine IoT Monitoring System

## 🌍 Project Overview
This project aims to **monitor and log real-time data** from a **Low RPM Wind Turbine (LRWT)** using IoT technology. It collects essential parameters like:
- **Wind Speed** (Anemometer)
- **RPM** (Hall Effect Sensor)
- **Temperature & Humidity** (DHT22 Sensor)
- **Voltage Output** (Voltage Sensor)

The data is sent to **ThingSpeak Cloud**, where it is visualized in real time.

---
## 🛠️ Hardware Components
- **ESP32/ESP8266** – Microcontroller with Wi-Fi
- **Anemometer** – Measures wind speed
- **Hall Effect Sensor** – Measures RPM
- **DHT22 Sensor** – Measures temperature & humidity
- **Voltage Sensor** – Monitors turbine output voltage

---
## 📡 Software & Tools
- **Arduino IDE** – For coding and uploading firmware
- **ThingSpeak** – Cloud platform for real-time data visualization
- **Python (Optional)** – For data analysis and visualization

---
## 🚀 Installation & Setup
### 1️⃣ **Clone the Repository**
```bash
git clone https://github.com/YOUR_USERNAME/low-wind-turbine.git
cd low-wind-turbine
```

### 2️⃣ **Set Up Arduino IDE**
- Install **ESP32/ESP8266 Board Manager**
- Install required libraries: `WiFi.h`, `HTTPClient.h`, `DHT.h`

### 3️⃣ **Configure ThingSpeak**
- Create an account on [ThingSpeak](https://thingspeak.com/)
- Create a **New Channel**
- Enable fields for **Wind Speed, RPM, Temperature, Voltage**
- Copy your **API Key** and update it in `main.ino`

### 4️⃣ **Upload the Code to ESP32**
- Connect ESP32 to your PC
- Open `low_wind_turbine.ino`
- Replace:
  ```cpp
  const char* ssid = "YOUR_WIFI_SSID";
  const char* password = "YOUR_WIFI_PASSWORD";
  String apiKey = "YOUR_THINGSPEAK_API_KEY";
  ```
- Upload the code and open the **Serial Monitor**

---
## 📊 Real-Time Data Visualization
Once the system is running, visit your **ThingSpeak Dashboard** to view real-time data trends.

---
## 🔧 Future Enhancements
✅ Battery monitoring & power analytics  
✅ AI-based predictive maintenance  
✅ Mobile app for real-time alerts  

---
## 📝 License
This project is open-source under the **MIT License**. Feel free to contribute!

---
## 🤝 Contributing
1. Fork the repo
2. Create a new branch (`feature-name`)
3. Commit your changes (`git commit -m 'Added feature XYZ'`)
4. Push to the branch (`git push origin feature-name`)
5. Open a Pull Request

---
## 📞 Contact
For any queries, reach out to **Your Name** at **your-email@example.com**

---
### ⭐ If you like this project, give it a star on GitHub! ⭐

