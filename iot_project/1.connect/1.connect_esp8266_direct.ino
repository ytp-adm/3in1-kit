/*************************************************************
  ESP8266ボード直接使用版
  
  このコードはESP8266ボード（NodeMCU、Wemos D1など）で直接実行します
  Arduino Unoは使用しません
  
  App project setup:
    Slider widget (0...100) on V1
 *************************************************************/

// Template ID, Device Name and Auth Token are provided by the Blynk.Cloud
#define BLYNK_TEMPLATE_ID "TMPL6Ap8AFTDj"
#define BLYNK_TEMPLATE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "hms-7Pe29huQvSXo3MbWjZKLaAr3aU9U"

// Comment this out to disable prints and save space
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
char ssid[] = "YOUR_WIFI_SSID";     // Replace with your WiFi name
char pass[] = "YOUR_WIFI_PASSWORD"; // Replace with your WiFi password

void setup()
{
  // Debug console
  Serial.begin(115200);
  
  Serial.println("Starting ESP8266 Blynk connection...");
  
  // Connect to WiFi and Blynk
  Blynk.begin(auth, ssid, pass);
  
  Serial.println("Connected to Blynk!");
}

void loop()
{
  Blynk.run();
}

// This function will be called every time Slider Widget
// in Blynk app writes values to the Virtual Pin V1
BLYNK_WRITE(V1)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  Serial.print("V1 Slider value is: ");
  Serial.println(pinValue);
}