#ifndef NETWORK_H
#define NETWORK_H

#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
// #include <PubSubClient.h>

// Declare MQTT clien
extern WiFiClient espClient;
// extern PubSubClient mqttClient;

// Command function prototypes
void cmd_ifconfig(char* args);
void cmd_ipconfig(char* args);  // alias
void cmd_scan(char* args);
void cmd_connect(char* args);
void cmd_ping(char* args);
// void cmd_curl(char* args);
// void cmd_mqtt(char* args);

#endif