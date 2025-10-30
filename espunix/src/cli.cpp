#include "cli.h"
#include <vector>

std::vector<Command> commands;

void registerCommand(const char* name, CommandFunction func, const char* description) {
    commands.push_back({name, func, description});
}

void processCLIInput(const char* input) {
    char buf[128];
    strncpy(buf, input, sizeof(buf));
    buf[sizeof(buf)-1] = 0;

    // Split command and args
    char* cmd = strtok(buf, " ");
    char* args = strtok(NULL, "");

    if (!cmd) return;

    for (auto &c : commands) {
        if (strcmp(c.name, cmd) == 0) {
            c.func(args);
            return;
        }
    }

    Serial.println("Unknown command. Type 'help' to list commands.");
}

void startCLI() {
    Serial.println("ESP32 CLI Ready. Type 'help'");
    while (1) {
        if (Serial.available()) {
            String line = Serial.readStringUntil('\n');
            line.trim();
            if (line.length()) processCLIInput(line.c_str());
        }
        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
}