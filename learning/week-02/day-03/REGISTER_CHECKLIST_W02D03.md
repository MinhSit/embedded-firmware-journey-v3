# Register Checklist — W02D03

Completed learner worksheet. Facts below come from official-source verification
and actual observations; unperformed measurements remain explicit.

## Target and electrical checks

- Board: NUCLEO-F446RE
- MCU: STM32F446RE
- Supply/logic voltage: 3.3V
- Common-ground check: N/A for onboard LED test; verify before external measurement.
- Target LED/output pin: PA5
- Source proving pin: UM1724 Rev 17, Table 19 — D13 -> PA5
- GPIO port: GPIOA
- Source proving port/pin: UM1724 Rev 17, Table 19
- LED polarity: Active-HIGH; PA5 HIGH -> LD2 ON, PA5 LOW -> LD2 OFF

## Register plan

- Peripheral clock register: RCC_AHB1ENR
- Clock-enable field: GPIOAEN, bit 0
- GPIO mode register: GPIOA_MODER
- Mode field: MODER5[1:0], bits 11:10; `01` = General purpose output
- Output register/mechanism:
  - GPIOA_ODR: ODR5 at bit 5
  - GPIOA_BSRR:
    - BS5 at bit 5 -> set PA5
    - BR5 at bit 21 -> reset PA5
- Output bit/mask:
  - GPIOAEN mask: `1U << 0`
  - MODER5 field mask: `0x3U << 10`
  - MODER5 output value: `0x1U << 10`
  - ODR5 mask: `1U << 5`
  - BSRR set mask: `1U << 5`
  - BSRR reset mask: `1U << 21`
- Expected register state before configuration:
  - GPIOA clock not assumed enabled before learner configuration.
  - PA5 mode not assumed to be output before learner configuration.
- Expected register state after configuration:
  - RCC_AHB1ENR.GPIOAEN = 1
  - GPIOA_MODER.MODER5 = `01`
  - PA5 driven HIGH for normal LED-on test
- Observed register state: NOT MEASURED

## Physical behavior

- Expected physical LED/pin behavior:
  - PA5 HIGH -> LD2 ON
  - PA5 LOW -> LD2 OFF
- Observed behavior:
  - Normal firmware: LD2 ON continuously after flashing.
  - Observed behavior matched expected behavior.

## Failure observation

- Failure case attempted:
  Temporarily removed/commented the GPIOA peripheral clock-enable operation.

- Hypothesis:
  Without GPIOA clock enabled, GPIOA would not operate as expected and PA5 would
  not be driven HIGH by the configured output path, so LD2 was expected to remain OFF.

- Measurement:
  Visual observation of onboard LD2 after clean build and flashing the modified firmware.

- Result:
  LD2 OFF with GPIOA clock enable removed.
  After restoring GPIOA clock enable, rebuilding and reflashing, LD2 returned ON.

## Source trace

- RM0390 section/page/revision:
  - Section 6.3.10 — RCC AHB1 peripheral clock enable register (RCC_AHB1ENR)
  - Section 7.4.1 — GPIO port mode register (GPIOx_MODER)
  - Section 7.4.6 — GPIO port output data register (GPIOx_ODR)
  - Section 7.4.7 — GPIO port bit set/reset register (GPIOx_BSRR)
  - Exact PDF page/revision: NOT RECORDED during session.

- Board manual or schematic section/page/revision:
  - UM1724 Rev 17
  - Section 7.6 — LEDs
  - Table 19 — ARDUINO connectors on NUCLEO-F446RE
  - D13 -> PA5
  - LD2 behavior: HIGH = ON, LOW = OFF

- Device datasheet section/page/revision:
  - STM32F446xC/E datasheet
  - Section 4 — Pinout and pin description
  - Exact PDF page/revision: NOT RECORDED during session.

- Other official source used:
  N/A
