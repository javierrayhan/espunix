# espunix

Linux-like Command Reference for ESP32 (FreeRTOS Shell)

**Microcontroller Supported**: ESP32
**Author**: Javier Rayhan  
**Project Start**: October 28, 2025
**Status**: Planning

---

## Filesystem & Directory Commands

| Command                | Description                                | Status |
| ---------------------- | ------------------------------------------ | ------ |
| `ls`                   | List directory contents (SPIFFS / SD card) |        |
| `cd <dir>`             | Change current directory                   |        |
| `pwd`                  | Display current working directory          |        |
| `mkdir <dir>`          | Create a new directory                     |        |
| `rm <file>`            | Delete a file                              |        |
| `cat <file>`           | Show file contents                         |        |
| `touch <file>`         | Create a new empty file                    |        |
| `echo <text> > <file>` | Write text to a file                       |        |
| `cp <src> <dest>`      | Copy file from source to destination       |        |
| `mv <src> <dest>`      | Move or rename a file                      |        |
| `df`                   | Show storage capacity and usage            |        |
| `find <name>`          | Search for a file by name                  |        |

---

## System Info & Management

| Command   | Description                               | Status |
| --------- | ----------------------------------------- | ------ |
| `free`    | Display RAM and heap usage                |        |
| `uptime`  | Show how long the system has been running |        |
| `ps`      | List active FreeRTOS tasks                |        |
| `top`     | Display CPU usage per task                |        |
| `reboot`  | Restart the ESP32 system                  |        |
| `version` | Show firmware or OS version               |        |
| `dmesg`   | Display kernel or startup logs            |        |
| `date`    | View or set the system time (RTC)         |        |

---

## Networking Commands (WiFi / HTTP / MQTT)

| Command                     | Description                         | Status |
| --------------------------- | ----------------------------------- | ------ |
| `ifconfig`                  | Show network status (IP, MAC, RSSI) |        |
| `ping <ip>`                 | Test network connectivity           |        |
| `scan`                      | Scan available WiFi networks        |        |
| `connect <ssid> <password>` | Connect to a WiFi network           |        |
| `curl <url>`                | Perform a simple HTTP GET request   |        |
| `mqtt <topic> <payload>`    | Publish an MQTT message             |        |
| `ipconfig`                  | Alias for `ifconfig` (optional)     |        |

---

## System Utilities & General Commands

| Command                  | Description                           | Status |
| ------------------------ | ------------------------------------- | ------ |
| `clear`                  | Clear terminal display                |        |
| `help`                   | Show all available commands           |        |
| `run <task>`             | Execute a specific task               |        |
| `kill <pid>`             | Stop a FreeRTOS task                  |        |
| `sleep <ms>`             | Pause execution temporarily           |        |
| `log`                    | Display system log buffer             |        |
| `history`                | Show previous command history         |        |
| `alias <name> <command>` | Create a shortcut for a command       |        |
| `set <var> <value>`      | Set environment variable              |        |
| `export <var>`           | Make variable persistent across tasks |        |

---

## Hardware I/O Commands

| Command                       | Description                            | Status |
| ----------------------------- | -------------------------------------- | ------ |
| `gpio set <pin> <value>`      | Set GPIO pin HIGH/LOW                  |        |
| `gpio read <pin>`             | Read GPIO pin status                   |        |
| `adc read <pin>`              | Read analog input value                |        |
| `pwm set <pin> <freq> <duty>` | Configure PWM frequency and duty cycle |        |
| `i2c scan`                    | Scan connected I2C devices             |        |
| `spi info`                    | Show SPI device information            |        |
| `sensor read <type>`          | Read sensor data (DHT22, soil, etc.)   |        |

---

## Scripting & Execution

| Command          | Description                    | Status |
| ---------------- | ------------------------------ | ------ |
| `sh <file>`      | Execute a shell script         |        |
| `exec <command>` | Execute inline command         |        |
| `cron`           | Schedule periodic tasks        |        |
| `scheduler`      | Show FreeRTOS scheduler status |        |
| `run -b <task>`  | Run task in background         |        |

---
