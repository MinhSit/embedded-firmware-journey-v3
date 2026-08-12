# W01D03 — Alignment / Endian Note

Date: 2026-08-12
Toolchain: Host GCC 14.2.0
AI mode used so far:

## 1. Prediction — fill before running measurements

### layout_a_t

| Item | Prediction | Reason |
|---|---:|---|
| sizeof | | |
| _Alignof | | |
| offset(tag) | | |
| offset(value) | | |
| offset(code) | | |
| internal padding | | |
| tail padding | | |

### layout_b_t

| Item | Prediction | Reason |
|---|---:|---|
| sizeof | | |
| _Alignof | | |
| offset(tag) | | |
| offset(value) | | |
| offset(code) | | |
| internal padding | | |
| tail padding | | |

## 2. Observed

Build command:

```text
TBD
```

Test command:

```text
TBD
```

### layout_a_t

```text
sizeof:
_Alignof:
offset(tag):
offset(value):
offset(code):
```

### layout_b_t

```text
sizeof:
_Alignof:
offset(tag):
offset(value):
offset(code):
```

## 3. Prediction mismatches

For each mismatch:

```text
Prediction:
Observed:
Why prediction was wrong:
Rule/mental model to keep:
```

## 4. Union observation

```text
sizeof(u32_view_t):
_Alignof(u32_view_t):
What shared storage means:
Why I am not using union-punning as my portable serialization baseline:
```

## 5. Endian observation

Use a value such as `0x01020304` and record the object bytes.

```text
Bytes at increasing addresses:
Detected host endian:
What endian means:
What endian does NOT mean:
```

## 6. Portability boundary

Write two short lists.

C-level concepts I can rely on:
-

Implementation/ABI observations I must re-measure or document:
-

## 7. Closed-book explanation

In your own words, 4–8 sentences:

- padding vs alignment;
- tail padding;
- member order and size;
- endian;
- why raw struct serialization is risky.

## 8. Final result

```text
Build: PASS / FAIL
Tests: PASS / FAIL
Tests run:
Tests failed:
Known issue:
```
