# SUBMIT — Week 02 / Day 01

Task:
W02D01 Cortex-M mental model / Thread-Handler + exception flow

Date:
2026-08-17

Highest AI Level Used:
AI-3

Files Changed:
- `learning/week-02/day-01/TODO_W02_D01.md`
- `learning/week-02/day-01/CORTEX_M_EXCEPTION_FLOW_W02D01.md`
- `learning/week-02/day-01/cortex_m_exception_flow.png`
- `learning/week-02/day-01/SUBMIT_W02_D01.md`

Official References Used:
ARM Cortex-M4 Generic User Guide / ARM DUI 0553A

Evidence:

Diagram:
`learning/week-02/day-01/cortex_m_exception_flow.png`

Closed-book reconstruction:
`learning/week-02/day-01/CORTEX_M_EXCEPTION_FLOW_W02D01.md` Section 9

Debugger/register observations:
NOT PERFORMED — previous STM32 baseline source was deleted. No hardware/debug
register observation was collected for W02D01.

Other:
Worksheet and learner notes:
`learning/week-02/day-01/CORTEX_M_EXCEPTION_FLOW_W02D01.md`

Expected:
Learner can reconstruct the practical Thread/Handler, MSP/PSP and exception
entry/return flow.

Observed:
The required diagram exists. Project Chat learning review found the core
practical mental model sufficient, and local worksheet/diagram evidence matches
the reviewed state.

What I can explain without AI:
- Thread mode runs normal execution and can use MSP or PSP; reset defaults to MSP.
- Handler mode processes exceptions, is always privileged and always uses MSP.
- Exception entry stacks the frame on the current Thread stack; Handler then uses MSP.
- EXC_RETURN identifies the return mode, restoration stack and floating-point-state information.
- Late-arriving, nested/preemption and tail-chaining are distinct flows.

What remains unclear:
- Detailed roles of xPSR and R0-R3/R12 in the exception stack frame.
- Deeper EXC_RETURN mechanics.

Known failures / misconceptions:
- Reset stack default was initially unclear.
- Exception-frame stack selection was initially unclear.
- EXC_RETURN responsibility was initially mixed with tail-chaining behavior.
- Timing among late-arriving, nested/preemption and tail-chaining required correction.

Questions for reviewer:
- What roles do xPSR and R0-R3/R12 play inside the exception stack frame?
- How does EXC_RETURN work in greater detail?

Next Action:
On the next roadmap session, BOOT W02D02 and begin power-on-to-main/startup-sequence work.
