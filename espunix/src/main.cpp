#include <Arduino.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"

#include "cli.h"
#include "network.h"

// ===== Command functions =====
void cmd_help(char* args) {
    Serial.println("Available commands:");
    for (size_t i = 0; i < commands.size(); i++) {
        Serial.printf("%-10s : %s\n", commands[i].name, commands[i].description);
    }
}

void cmd_free(char* args) {
    Serial.printf("Heap free: %u bytes\n", esp_get_free_heap_size());
}

void cmd_uptime(char* args) {
    uint32_t ms = millis();
    Serial.printf("Uptime: %lu.%03lu seconds\n", ms/1000, ms%1000);
}

void cmd_ps(char* args) {
  Serial.println("Active tasks (basic):");
  Serial.printf("Task count: %u\n", (unsigned)uxTaskGetNumberOfTasks());
  TaskHandle_t current = xTaskGetCurrentTaskHandle();
  Serial.printf("Current task: %s\n", pcTaskGetName(current));
  Serial.printf("Free heap: %u bytes\n", (unsigned)esp_get_free_heap_size());
}

void cmd_reboot(char* args) {
    Serial.println("Rebooting...");
    esp_restart();
}

void cmd_version(char* args) {
    Serial.println("espunix OS version: 1.0.0"); 
}

// ===== Setup =====
void setup() {
    Serial.begin(115200);
    delay(2000);

    // Register commands
    registerCommand("help", cmd_help, "List commands");
    registerCommand("free", cmd_free, "Display RAM and heap usage");
    registerCommand("uptime", cmd_uptime, "Show system uptime");
    registerCommand("ps", cmd_ps, "List active tasks");
    registerCommand("reboot", cmd_reboot, "Restart ESP32");
    registerCommand("version", cmd_version, "Show firmware/OS version");
    
    registerCommand("ifconfig", cmd_ifconfig, "Show network status (IP, MAC, RSSI)");
    registerCommand("ipconfig", cmd_ipconfig, "Alias for ifconfig");
    registerCommand("ping", cmd_ping, "Test network connectivity");
    registerCommand("scan", cmd_scan, "Scan available WiFi networks");
    registerCommand("connect", cmd_connect, "Connect to a WiFi network");
    // registerCommand("curl", cmd_curl, "Perform HTTP GET request");
    // registerCommand("mqtt", cmd_mqtt, "Publish MQTT message");

    // Start CLI in FreeRTOS task
    xTaskCreate(
        [](void*){
            startCLI();
        },
        "CLI Task",
        4096,
        NULL,
        1,
        NULL
    );
}

void loop() {
    // Nothing needed, CLI runs in separate task
}