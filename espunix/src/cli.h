#pragma once
#include <Arduino.h>
#include <vector>

typedef void (*CommandFunction)(char* args);

struct Command {
    const char* name;
    CommandFunction func;
    const char* description;
};

// Command parser functions
void registerCommand(const char* name, CommandFunction func, const char* description);
void processCLIInput(const char* input);
void startCLI();

// Expose global commands list
extern std::vector<Command> commands;