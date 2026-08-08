# HARDWARE INVENTORY — V3

Date:
2026-08-09

## Required / Core

| Item | Present | Working | Notes |
|---|---|---|---|
| Nucleo-F446RE | TBD | TBD | Primary STM32 board |
| USB data cable | TBD | TBD | |
| ESP32-WROOM-32 dev board | TBD | TBD | |
| MPU6050 | TBD | TBD | Required sensor |
| Logic analyzer 8ch | TBD | TBD | |
| Jumper wires | TBD | TBD | |

## Optional

| Item | Present | Working | Notes |
|---|---|---|---|
| Multimeter | TBD | TBD | |
| SSD1306 OLED | TBD | TBD | UART is fallback |
| W25Q64 | TBD | TBD | |
| RTC | TBD | TBD | |
| DHT21 | TBD | TBD | |
| CAN transceiver | TBD | TBD | |

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

## Fallbacks

Sensor unavailable:
Use mock data where roadmap permits.

OLED unavailable:
Use UART output.

Optional module unavailable:
Do not block core roadmap.
