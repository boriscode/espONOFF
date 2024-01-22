
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

const char* ssid = ""; // Replace with your SSID
const char* password = ""; // Replace with your Wi-Fi password

const char* serverName = "http://address/get_state.php"; // replace with your url
const int relayPin = 5; // Replace with your GPIO pin number

void setup() {
  Serial.begin(115200);
  
  // Initialize the relay pin as an output
  pinMode(relayPin, OUTPUT);
  
  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
}

void loop() {
  if(WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    
    http.begin(serverName); // Specify the URL
    int httpCode = http.GET(); // Make the request
    
    if (httpCode > 0) { // Check the returning code
      String payload = http.getString(); // Get the request response payload
      Serial.println(payload);

      // Parse the JSON response
      DynamicJsonDocument doc(1024);
      deserializeJson(doc, payload);
      String state = doc["state"];

      // Set the relay state
      if(state == "on") {
        digitalWrite(relayPin, HIGH); // Set the GPIO pin to HIGH
      } else if(state == "off") {
        digitalWrite(relayPin, LOW); // Set the GPIO pin to LOW
      }
    }
    http.end(); // Close connection
  } else {
    Serial.println("Error in WiFi connection");
  }
  
  delay(10000); // Wait for 10 seconds before making the next request
}
