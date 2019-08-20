#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>

// WiFi Parameters
const char* ssid     =""; // Your ssid
const char* password = ""; // Your Password



int ledPinR = 13; //13; // GPIO13---D7 of NodeMCU RED
int ledPinY = 12; //12; // GPIO13---D6 of NodeMCU Yellow
int ledPinG = 14;//14; // GPIO13---D5 of NodeMCU Green
void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  pinMode(ledPinR, OUTPUT);
  digitalWrite(ledPinR, LOW);

    pinMode(ledPinG, OUTPUT);
  digitalWrite(ledPinG, LOW);

    pinMode(ledPinY, OUTPUT);
  digitalWrite(ledPinY, LOW);


  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting...");
  }













}

void loop() {
  // Check WiFi Status
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;  //Object of class HTTPClient
    http.begin("Alamat_Web");
    int httpCode = http.GET();
    //Check the returning code
    if (httpCode > 0) {
      // Parsing

      const size_t bufferSize = JSON_OBJECT_SIZE(34) + 840;

      DynamicJsonBuffer jsonBuffer(bufferSize);

      JsonObject& root = jsonBuffer.parseObject(http.getString());

      // Parameters

  

const char* mac = root["mac"]; // 
int clientCount = root["clientCount"]; // 17

      // Output to serial monitor
      Serial.print("Name:");
      Serial.println(mac);
      Serial.print("clientCount:  ");
      Serial.println(clientCount);
      //ACTUATOR


  if (clientCount >= 20)  {
    digitalWrite(ledPinR, HIGH);
    digitalWrite(ledPinY, LOW);
    digitalWrite(ledPinG, LOW);

  } else
  if (clientCount >= 10 )  {
    digitalWrite(ledPinR, LOW);
    digitalWrite(ledPinY, HIGH);
    digitalWrite(ledPinG, LOW);
 } else
 if (clientCount >= 0)   {
    digitalWrite(ledPinR, LOW);
    digitalWrite(ledPinY, LOW);
    digitalWrite(ledPinG, HIGH);
 }

  // Delay
  delay(5000);

    }
    http.end();   //Close connection
  }

}
