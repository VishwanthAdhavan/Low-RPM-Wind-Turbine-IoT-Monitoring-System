#include <WiFi.h>
#include <HTTPClient.h>
#include "DHT.h"

// ThingSpeak API Key
const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";
String apiKey = "YOUR_THINGSPEAK_API_KEY";

// Sensor Pins
#define DHTPIN 4         // DHT22 Sensor Pin
#define DHTTYPE DHT22
#define WIND_SENSOR 32   // Anemometer Pin
#define RPM_SENSOR 34    // Hall Effect Sensor for RPM
#define VOLTAGE_SENSOR 35 // Voltage Sensor Pin

DHT dht(DHTPIN, DHTTYPE);

int rpmCount = 0;
unsigned long lastMillis = 0;

// Interrupt function for RPM counting
void IRAM_ATTR rpmCounter() {
    rpmCount++;
}

// Setup function
void setup() {
    Serial.begin(115200);
    WiFi.begin(ssid, password);
    
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to WiFi...");
    }
    
    Serial.println("Connected to WiFi!");
    
    dht.begin();
    pinMode(WIND_SENSOR, INPUT);
    pinMode(VOLTAGE_SENSOR, INPUT);
    attachInterrupt(digitalPinToInterrupt(RPM_SENSOR), rpmCounter, RISING);
}

// Function to read wind speed (Example conversion)
float readWindSpeed() {
    int windValue = analogRead(WIND_SENSOR);
    return (windValue / 1024.0) * 30.0; // Scale to max wind speed (30 m/s example)
}

// Function to read voltage (Example conversion)
float readVoltage() {
    int rawValue = analogRead(VOLTAGE_SENSOR);
    return (rawValue * 5.0) / 1023.0;  // Assuming 0-5V sensor
}

// Function to calculate RPM
float calculateRPM() {
    float rpm = (rpmCount * 60.0) / 2.0;  // Example conversion
    rpmCount = 0;
    return rpm;
}

// Send data to ThingSpeak
void sendToThingSpeak(float windSpeed, float temperature, float rpm, float voltage) {
    if (WiFi.status() == WL_CONNECTED) {
        HTTPClient http;
        String url = "http://api.thingspeak.com/update?api_key=" + apiKey +
                     "&field1=" + String(windSpeed) +
                     "&field2=" + String(temperature) +
                     "&field3=" + String(rpm) +
                     "&field4=" + String(voltage);
        
        http.begin(url);
        int httpCode = http.GET();
        http.end();
        
        Serial.println("Data Sent to ThingSpeak!");
    }
}

void loop() {
    float windSpeed = readWindSpeed();
    float temperature = dht.readTemperature();
    float rpm = calculateRPM();
    float voltage = readVoltage();
    
    Serial.print("Wind Speed: "); Serial.print(windSpeed); Serial.println(" m/s");
    Serial.print("Temperature: "); Serial.print(temperature); Serial.println(" °C");
    Serial.print("RPM: "); Serial.print(rpm); Serial.println(" RPM");
    Serial.print("Voltage: "); Serial.print(voltage); Serial.println(" V");

    sendToThingSpeak(windSpeed, temperature, rpm, voltage);
    
    delay(15000); // Send data every 15 seconds
}
