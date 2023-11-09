#include <WiFi.h>
#include <HTTPClient.h>

const int redPin = 17;
const int greenPin = 18;
const int bluePin = 19;
const int lightSensorPin = 4;

const int lightThreshold = 500; // Adjust this threshold as needed

const char* ssid = "TKZ-10";
const char* password = "Careful11well";
const char* serverAddress = "http://localhost:8000"; // Replace with your Node.js server's IP and port

String currentColor = "off";

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(lightSensorPin, INPUT);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");
}

void loop() {
  int lightLevel = analogRead(lightSensorPin);

  if (lightLevel < lightThreshold) {
    setColor("off");
  }

  delay(1000); // Adjust the delay as needed to prevent rapid color changes
}

void setColor(String color) {
  if (color == "blue") {
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, HIGH);
  } else if (color == "red") {
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
  } else if (color == "off") {
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
  }
}

void sendColorToServer(String color) {
  HTTPClient http;
  String url = String(serverAddress) + "/setcolor?color=" + color; // Use the String class for URL building

  http.begin(url);
  int httpResponseCode = http.GET();

  if (httpResponseCode == 200) {
    Serial.println("Color set successfully");
  } else {
    Serial.println("Error setting color");
  }

  http.end();
}


