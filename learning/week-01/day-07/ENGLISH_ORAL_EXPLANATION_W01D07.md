# W01D07 English Oral Explanation

Evidence classification: `CHAT-DERIVED ORAL-PRACTICE NOTE`

Evidence role: `NON-COMPETENCY COMMUNICATION EVIDENCE`

Date: `2026-08-15`

Topic: `Why volatile does not make code thread-safe`

Delivery: The learner delivered the explanation orally in a live ChatGPT Voice
conversation.

English delivery result: `COMPLETED`

Standalone audio file retained: `NO`

Exact spoken duration: `NOT INDEPENDENTLY MEASURED`

## Provenance and limitations

- No separate audio recording is available in this repository.
- The source conversation contained live automatic speech transcription.
- Automatic speech recognition may misrecognize technical words such as
  `volatile`; this note is not a forensic or verbatim audio transcript.
- The learner used AI assistance to structure and edit the English wording
  before speaking. The W01D07 roadmap card explicitly allowed that assistance
  for the English/communication activity.
- This activity is outside the scored AI-0 `W01-C-FOUND` gate. It neither
  changes nor contaminates the gate's recorded AI provenance.

## Ideas covered orally

The learner covered these ideas during the oral explanation:

- `volatile` tells the compiler that a value may change unexpectedly;
- volatile accesses must be treated as observable accesses;
- `volatile` does not make an operation atomic;
- `count++` is conceptually a read-modify-write sequence;
- interrupt/main-context interleaving can cause a lost update or race condition;
- `volatile` does not provide locking or synchronization;
- `volatile` is not a mutex or a memory barrier;
- shared data may require an appropriate synchronization mechanism; and
- in summary, `volatile` controls compiler treatment of accesses but does not
  make code thread-safe.

## AI-assisted speaking script / content reference

The following is an AI-assisted speaking reference. It is not labeled as
learner-authored text and is not AI-0 evidence.

> Hello. Today I want to explain why volatile does not make code thread-safe.
>
> In C, volatile tells the compiler that a value may change unexpectedly.
>
> For example, the value can be changed by hardware, by an interrupt, or by
> another execution context.
>
> Because of this, the compiler must treat volatile accesses as observable
> accesses.
>
> It should not simply remove an access or assume that the value never changes.
>
> But volatile does not make an operation atomic.
>
> Atomic means the operation happens as one indivisible action.
>
> For example, count++ looks like one line of C code, but it is not necessarily
> one atomic operation.
>
> Conceptually, it can be a read, then a modify, and then a write.
>
> If the main program and an interrupt both execute count++, their operations
> can interleave.
>
> One context may read the old value before the other context writes the new
> value.
>
> This can cause a lost update.
>
> So even if count is declared volatile, a race condition can still happen.
>
> Volatile also does not provide locking.
>
> It does not provide synchronization.
>
> It is not a mutex.
>
> It is not a memory barrier.
>
> So volatile is useful when the compiler must see that a value can change
> outside normal program flow.
>
> But volatile alone does not protect shared data.
>
> If multiple contexts access shared data, another synchronization mechanism
> may be needed depending on the system.
>
> In short, volatile controls compiler treatment of accesses, but it does not
> make the code thread-safe.
>
> Thank you.

Commit: `SELF — containing commit`
