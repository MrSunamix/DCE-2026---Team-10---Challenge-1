#include <Arduino.h>
#include <stdio.h>
#include <OOCSI.h>
#include <WiFi.h>
#define SEP "/"
#define COURSE "OOCSI-things"
#define TEAM "team-XX"
#define THING "name_your_thing_here"

const char* OOSCIName = COURSE SEP TEAM SEP THING;
const char* OOSCIChannel = COURSE SEP TEAM;

//const char* ssid = "iotroam"; // Change if you are not using iotroam
//const char* password = "your_password_here";
const char* hostserver = "oocsi.id.tue.nl";

OOCSI oosci = OOCSI();
const int ldrPin = 0;

// --- Averaging config ---
const int NUM_SAMPLES = 10;

float readAveragedVoltage(int pin) {
  long sum = 0;
  for (int i = 0; i < NUM_SAMPLES; i++) {
    sum += analogRead(pin);
    delay(5);
  }
  float average = sum / (float)NUM_SAMPLES;
  float voltage = (average / 4095.0) * 3.3;
  return 3.3 - voltage;
}

void setup() {
  Serial.begin(115200);
  delay(100);
  WiFi.mode(WIFI_STA);
  oosci.connect(OOSCIName, hostserver, ssid, password);
  oosci.subscribe(OOSCIChannel);
  pinMode(ldrPin, INPUT);
}

void loop() {
  float voltage = readAveragedVoltage(ldrPin);

  oosci.newMessage(OOSCIChannel);
  oosci.addFloat("ldr", voltage);
  oosci.sendMessage();
  oosci.printSendMessage();
  oosci.keepAlive();

  delay(10);
}
