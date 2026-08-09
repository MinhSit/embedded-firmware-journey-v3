# HARDWARE INVENTORY — V3

Date:
2026-08-09

Status semantics:
- `YES` = physically present.
- `PASS` = function was exercised during Sprint 0.
- `NOT_TESTED` = present but function was not electrically exercised during Sprint 0.
- `NO` = not currently confirmed in inventory.

## Required / Core

| Item | Present | Working | Notes |
|---|---|---|---|
| Nucleo-F446RE | YES | PASS | Primary STM32 board; build/flash/debug/blink revalidated in Sprint 0 |
| USB data cable | YES | PASS | Data transfer proven by STM32/ESP32 flash/debug/monitor workflows |
| ESP32-WROOM-32 dev board | YES | PASS | Inventory includes ESP32-WROOM-32D; build/flash/monitor revalidated |
| MPU6050 | YES | NOT_TESTED | Module present, headers soldered, visually new/clean with no visible damage; electrical/I2C test deferred to sensor phase |
| Logic analyzer 8ch | YES | PASS | 24 MHz 8-channel unit; detected in PulseView and captured STM32 blink waveform |
| Jumper wires | YES | NOT_TESTED | Multiple male/male, female/female, male/female sets plus 140-wire breadboard kit; individual wires not exhaustively tested |

## Optional

| Item | Present | Working | Notes |
|---|---|---|---|
| Multimeter | YES | NOT_TESTED | XL830L present |
| SSD1306 OLED | YES* | NOT_TESTED | 0.96-inch IIC OLED present; exact controller IC not yet verified as SSD1306. UART remains fallback |
| W25Q64 | YES | NOT_TESTED | W25Q64 flash module present |
| RTC | YES | NOT_TESTED | DS1307 + AT24C32 module present |
| DHT21 | YES | NOT_TESTED | DHT21 module present |
| CAN transceiver | NO | N/A | Not found in current consolidated inventory; optional and does not block core roadmap |

## Additional Useful Hardware — Non-Core

Current consolidated inventory also includes Arduino UNO R3, STM32C8T6 board, breadboards, LEDs/resistors/buttons, 74HC595, RC522, LCD1602 + I2C adapter, keypad, relay, NE555, motors/servo, ultrasonic/light/sound/rain/soil sensors and soldering tools.

These are available for bounded labs when they support a roadmap competency. They do not create new mandatory scope before v1.0.

## Electrical Safety

Logic level baseline:
3.3 V

Before wiring verify:

- voltage;
- common ground;
- exact pin;
- alternate function;
- direction;
- connector;
- current/power assumptions.

Sprint 0 observation:
- STM32 target voltage reported at 3.30 V during ST-Link session.
- Common ground was used for the logic-analyzer capture.

## Fallbacks

Sensor unavailable or temporarily unverified:
Use mock data where roadmap permits.

OLED unavailable/unverified:
Use UART output.

Optional module unavailable:
Do not block core roadmap.

## Sprint 0 Inventory Decision

Core hardware required to begin Week 1 is available. No current hardware blocker requires Sprint 0 recovery.
