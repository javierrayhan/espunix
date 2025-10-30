#include "network.h"

WiFiClient espClient;
// PubSubClient mqttClient(espClient);

void cmd_ifconfig(char* args) {
    if (WiFi.status() == WL_CONNECTED) {
        Serial.println("=== Network Info ===");
        Serial.printf("SSID: %s\n", WiFi.SSID().c_str());
        Serial.printf("IP: %s\n", WiFi.localIP().toString().c_str());
        Serial.printf("MAC: %s\n", WiFi.macAddress().c_str());
        Serial.printf("RSSI: %d dBm\n", WiFi.RSSI());
    } else {
        Serial.println("WiFi not connected.");
    }
}

void cmd_ipconfig(char* args) {
    cmd_ifconfig(args); // alias
}

void cmd_scan(char* args) {
    Serial.println("Scanning WiFi networks...");
    int n = WiFi.scanNetworks();
    if (n == 0) {
        Serial.println("No networks found.");
    } else {
        Serial.printf("%d networks found:\n", n);
        for (int i = 0; i < n; ++i) {
            Serial.printf("%d: %s (%d dBm) %s\n",
                          i + 1,
                          WiFi.SSID(i).c_str(),
                          WiFi.RSSI(i),
                          (WiFi.encryptionType(i) == WIFI_AUTH_OPEN) ? "Open" : "Encrypted");
        }
    }
}

void cmd_connect(char* args) {
    char ssid[64], pass[64];
    if (sscanf(args, "%63s %63s", ssid, pass) == 2) {
        Serial.printf("Connecting to %s...\n", ssid);
        WiFi.mode(WIFI_STA);
        WiFi.begin(ssid, pass);
        int timeout = 0;
        while (WiFi.status() != WL_CONNECTED && timeout < 20) {
            delay(500);
            Serial.print(".");
            timeout++;
        }
        Serial.println();
        if (WiFi.status() == WL_CONNECTED) {
            Serial.println("Connected!");
            cmd_ifconfig(nullptr);
        } else {
            Serial.println("Failed to connect.");
        }
    } else {
        Serial.println("Usage: connect <ssid> <password>");
    }
}

void cmd_ping(char* args) {
    if (strlen(args) == 0) {
        Serial.println("Usage: ping <ip>");
        return;
    }

    Serial.printf("Pinging %s...\n", args);
    IPAddress ip;
    if (!WiFi.hostByName(args, ip)) {
        Serial.println("Host not found.");
        return;
    }

    WiFiClient client;
    unsigned long start = millis();
    if (client.connect(ip, 80)) {
        unsigned long elapsed = millis() - start;
        Serial.printf("Reply from %s: time=%lu ms\n", ip.toString().c_str(), elapsed);
        client.stop();
    } else {
        Serial.println("Request timed out.");
    }
}

// void cmd_curl(char* args) {
//     if (WiFi.status() == WL_CONNECTED){
//         if (strlen(args) == 0) {
//             Serial.println("Usage: curl <url>");
//             return;
//         }

//         HTTPClient http;
//         http.begin(args);
//         int httpCode = http.GET();

//         if (httpCode > 0) {
//             String payload = http.getString();
//             Serial.printf("HTTP %d\n", httpCode);
//             Serial.println(payload);
//         } else {
//             Serial.printf("HTTP GET failed, error: %s\n", http.errorToString(httpCode).c_str());
//         }
//         http.end();
//     }
// }

// void cmd_mqtt(char* args) {
//     if (WiFi.status() == WL_CONNECTED) {
//         char topic[64], payload[64];
//         if (sscanf(args, "%63s %63s", topic, payload) != 2) {
//             Serial.println("Usage: mqtt <topic> <payload>");
//             return;
//         }

//         if (!mqttClient.connected()) {
//             mqttClient.setServer("test.mosquitto.org", 1883);
//             Serial.print("Connecting to MQTT...");
//             while (!mqttClient.connected()) {
//                 if (mqttClient.connect("ESP32Client")) break;
//                 Serial.print(".");
//                 delay(500);
//             }
//             Serial.println();
//             if (mqttClient.connected()) Serial.println("Connected to MQTT broker.");
//             else {
//                 Serial.println("MQTT connection failed.");
//                 return;
//             }
//         }

//         mqttClient.publish(topic, payload);
//         Serial.printf("Published to %s: %s\n", topic, payload);
//     }
// }