# W01D06 Post-Gate Review and Correction

Assessment ID: `W01D06-C-CODING-01`

Phase: after `CLOSE ATTEMPT`

AI mode: `AI-3 — review/correction`

Score effect: none. The raw score remains `98/100 PASS`.

## Learner-Supplied Correction

`sizeof(src)` is the size of the pointer, not the string.

Example:
On a 64-bit platform `sizeof(src)` can be 8.
A source object `"Hi"` occupies 3 bytes including `'\0'`.
`memcpy(dst, src, sizeof(src))` therefore requests 8 source bytes and may access
beyond the source object.

## Semantic Clarification Recorded During Review

The C language does not guarantee that bytes accessed beyond the source object
are merely "garbage". Once the read accesses outside the source object, behavior
is undefined. Possible observed outcomes include apparently normal execution,
unrelated data, a fault, or other behavior.

This correction is post-gate evidence. It does not rewrite the raw answer or
retroactively change the score.
