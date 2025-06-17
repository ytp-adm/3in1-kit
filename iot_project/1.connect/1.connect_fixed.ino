/*************************************************************
  WARNING!
    It's very tricky to get it working. Please read this article:
    http://help.blynk.cc/hardware-and-libraries/arduino/esp8266-with-at-firmware

  You can use this sketch as a debug tool that prints all incoming values
  sent by a widget connected to a Virtual Pin 1 in the Blynk App.

  App project setup:
    Slider widget (0...100) on V1
 *************************************************************/

// Template ID, Device Name and Auth Token are provided by the Blynk.Cloud
// See the Device Info tab, or Template settings
#define BLYNK_TEMPLATE_ID "TMPL6Ap8AFTDj"
#define BLYNK_TEMPLATE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "hms-7Pe29huQvSXo3MbWjZKLaAr3aU9U"

// Comment this out to disable prints and save space
#define BLYNK_PRINT Serial

#include <Arduino.h>
#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
// TODO: Move these to a separate config file or use WiFiManager
char ssid[] = "YOUR_WIFI_SSID";     // Replace with your WiFi name
char pass[] = "YOUR_WIFI_PASSWORD"; // Replace with your WiFi password

// Hardware Serial on Mega, Leonardo, Micro...
// #define EspSerial Serial1

// or Software Serial on Uno, Nano...
#include <SoftwareSerial.h>
SoftwareSerial EspSerial(2, 3); // RX, TX

// Your ESP8266 baud rate:
#define ESP8266_BAUD 115200

ESP8266 wifi(&EspSerial);

void setup()
{
  // Debug console
  Serial.begin(115200);
  
  // Wait for serial port to connect
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  
  Serial.println("Starting ESP8266 connection...");

  // Set ESP8266 baud rate
  EspSerial.begin(ESP8266_BAUD);
  delay(10);

  // Initialize Blynk
  Serial.println("Connecting to Blynk...");
  Blynk.begin(auth, wifi, ssid, pass);
  
  // You can also specify server:
  //Blynk.begin(auth, wifi, ssid, pass, "blynk.cloud", 80);
  //Blynk.begin(auth, wifi, ssid, pass, IPAddress(192,168,1,100), 8080);
  
  Serial.println("Connected to Blynk!");
}

void loop()
{
  Blynk.run();
  // You can inject your own code or combine it with other sketches.
  // Check other examples on how to communicate with Blynk. Remember
  // to avoid delay() function!
}