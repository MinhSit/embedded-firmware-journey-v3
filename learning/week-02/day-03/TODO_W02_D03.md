# TODO — Week 02 / Day 03

## Metadata

- Date: `2026-08-19`
- Week/Day: `Week 02 / Day 03`
- Topic: `RCC + register-level GPIO output`
- Day type: `LEARNING`
- Board: `Nucleo-F446RE`
- MCU: `STM32F446RE`
- Available Focused Time: `6h — learner input`
- Planned Focused Time: `6h`
- AI boundary: `AI-1/AI-2 before implementation; AI-3 review after meaningful attempt; AI-5 overall for executor infrastructure/evidence assistance`
- Competency status: `no new competency PASS from this day`

## Outcome

Read the relevant official RCC/GPIO material, independently implement peripheral
clock enable and GPIO output configuration at register level, produce a clean
build, run a real-hardware smoke test, and retain LED-demo plus register-checklist
evidence.

## Prerequisites

- Explain the reset-to-`main()` path from W02D02 at a working level.
- Use C bit operations without undefined shifts or accidental field damage.
- Identify the exact board, MCU, and official document revisions before coding.

## Official-source verification fields

- RM0390 revision/date and relevant sections: exact PDF revision/date not recorded
  during the session; Sections 6.3.10, 7.4.1, 7.4.6 and 7.4.7 verified.
- Nucleo-F446RE user manual or schematic revision/date and relevant sections:
  UM1724 Rev 17, Section 7.6 and Table 19.
- STM32F446RE datasheet revision/date and relevant sections: STM32F446xC/E
  datasheet, Section 4; exact PDF revision/date not recorded during the session.
- Evidence that the selected board output maps to the selected MCU pin:
  UM1724 Rev 17 Table 19 maps D13 to PA5; onboard user LED is LD2.
- Evidence for the required clock, mode, output mechanism, and polarity:
  RCC_AHB1ENR.GPIOAEN bit 0; GPIOA_MODER.MODER5 bits 11:10 = `01`;
  GPIOA_BSRR BS5 bit 5 / BR5 bit 21; PA5 HIGH -> LD2 ON and LOW -> OFF.

Do not copy values from tutorials or generated code. Record the source trail in
`REGISTER_CHECKLIST_W02D03.md` before implementation.

## Learner TODO

- [x] Verify the target LED/output pin and polarity from official board sources.
- [x] Verify the GPIO port and peripheral clock path from official MCU sources.
- [x] Derive the clock-enable field and GPIO mode field without magic constants.
- [x] Implement the marked RCC/GPIO TODOs in `firmware/stm32/w02d03-gpio-lab/main.c`.
- [x] Build cleanly and inspect the compiler/linker output.
- [x] Flash only during the learner session after Project Chat activates the day.
- [x] Observe the normal behavior and one deliberate negative/failure case.
- [x] Complete the register checklist and submission evidence.
- [x] Explain the read-modify-write choices and expected/observed behavior.

## Build procedure

From the lab directory:

```powershell
powershell -ExecutionPolicy Bypass -File .\build.ps1 -Clean
```

Confirm exit code `0`, review all compiler/linker output, and verify the expected
ELF, map, and list artifacts under `build/`. A clean starter build is not an
artifact PASS.

## Hardware smoke-test procedure

1. Reconfirm board orientation, target pin, supply/logic voltage, and common ground.
2. Build the learner implementation and review warnings before flashing.
3. Connect the Nucleo board through the known data-capable USB path.
4. Flash using the normal verified STM32 workflow.
5. Observe the LED/output behavior and, when useful, measure the pin electrically.
6. Record expected versus actual behavior; do not record an unperformed action.

## Negative/failure observation

Attempt one safe, reversible failure case chosen with Project Chat after the
normal path works. Predict the effect first, change one variable only, measure
the result, restore the working state, and record hypothesis/measurement/result.
Do not create an electrical short or exceed board/device limits.

## Evidence to save

- Official source identifiers and exact section/page references.
- Completed `REGISTER_CHECKLIST_W02D03.md` in the learner's own words.
- Learner-owned source diff with no HAL/LL GPIO initialization.
- Exact clean-build command, exit code, warnings, ELF/map/list paths.
- Flash command/result actually run during the learner session.
- Expected versus observed LED/pin behavior.
- Negative-case hypothesis, one-variable change, measurement, and restoration.
- Photo/video/debugger/register evidence only when actually captured.

## Self-explanation prompts

- Why must the peripheral clock be enabled before accessing/configuring GPIO?
- How did you derive the mode field while preserving unrelated pins?
- Why did you choose the output write mechanism used in your implementation?
- What does LED polarity change about software-visible behavior?
- Which observation would distinguish a clock error from a pin-mode error?

## Artifact stop condition

Stop only after the learner implementation builds cleanly, the real-hardware
normal path and one safe failure observation are recorded truthfully, the
register checklist is complete, and the learner can explain the decisions.
This may support an artifact result later; it cannot independently award a new
competency PASS.

## AI usage rules

- AI-1 theory and AI-2 hints are allowed before implementation.
- AI-3 review/debug is allowed only after a meaningful learner attempt.
- Do not request or accept AI-4/AI-5 core RCC/GPIO implementation during this prep.
- Disclose any stronger assistance if it occurs; do not relabel it downward.

## Submission format

Complete `SUBMIT_W02_D03.md` with exact source paths, commands, results,
measurements, expected-versus-actual notes, failure evidence, and the learner's
own explanation. Leave assessment/review fields unresolved for later review.

## Forbidden shortcuts

- No HAL/LL or generated GPIO initialization that bypasses register reasoning.
- No copied tutorial/blog solution, hidden solution file, or unexplained magic constants.
- No fabricated flash, register, electrical, or LED observation.
- No changing startup/linker/vendor infrastructure to avoid the learner task.
- No artifact/competency/lifecycle claim based only on a clean scaffold build.
