# W01D01 — Pointer / Array / Const

## AI Mode

AI-1 / AI-2 for learning; AI-3 review/debug after learner attempts.

Provenance note: actual highest AI level reached `AI-4` because E06 exposed the exact implementation line `*slot = target;` after a meaningful learner attempt. This does not invalidate the learning/practice artifact, but W01D01 must not be used as independent competency evidence.

Core implementation phải tự viết.

---

## E01 — swap_int

TODO:
- Validate pointer inputs.
- Swap values.
- Think about `a == b`.

Question:
- Nếu `a == b`, có cần coi là lỗi không? Vì sao?

---

## E02 — sum_ints

TODO:
- Validate `arr`, `len`, `out_sum`.
- Compute sum.

Questions:
- Vì sao output dùng pointer?
- `NULL + len == 0` có ý nghĩa gì theo API contract?

---

## E03 — max_int

TODO:
- Validate input.
- Find maximum.

Question:
- Vì sao không thể xác định maximum khi `len == 0` theo API hiện tại?

---

## E04 — reverse_ints

TODO:
- Reverse in-place.
- Không dùng array phụ.

Questions:
- Pointer/index nào tiến từ đầu?
- Pointer/index nào tiến từ cuối?
- Stop condition là gì?

---

## E05 — find_first

TODO:
- Tìm target đầu tiên.
- Return pointer tới element đó.
- Không tìm thấy => `NULL`.

Question:
- Vì sao return pointer có thể hữu ích hơn return index trong một số API?

---

## E06 — retarget_pointer

TODO:
- Validate `slot`.
- Làm cho caller's pointer trỏ sang `target`.

Question:
- Tại sao phải dùng `int **` thay vì `int *`?

Provenance:
- Learner had a meaningful attempt before review.
- AI later exposed the exact implementation line `*slot = target;`.
- Classification: bounded `AI-4` implementation exposure for E06.

---

## E07 — transform_ints

TODO:
- Validate input.
- Gọi function pointer cho từng element.
- Ghi kết quả trở lại array.

Questions:
- `fn` chứa cái gì?
- `fn(value)` thực chất đang làm gì?

---

## E08 — const placement

Không compile trước khi reasoning.

Với từng declaration, ghi:

1. pointer có đổi được không?
2. object qua pointer có đổi được không?

~~~c
const int *p1;
int const *p2;
int *const p3 = NULL;
const int *const p4 = NULL;
~~~

---

## E09 — one-past-end / pointer arithmetic

Không compile trước khi reasoning.

~~~c
int a[4] = {1, 2, 3, 4};
int *p1 = a + 4;

/* A */
int *p2 = a + 3;
int x = *p2;

/* B */
int y = *p1;

/* C */
int *p3 = &a[0];
p3 += 2;
int z = *p3;
~~~

Phân loại A / B / C:

- `DEFINED`
- `UNDEFINED`

Giải thích ngắn lý do.

---

## Completion Record

Date: 2026-08-10

- E01–E07: PASS
- E08 const placement: PASS
- E09 one-past-end: PASS
- Host tests: 46 / 46 PASS
- Self-explain: PASS
- Highest AI level used: AI-4 — bounded E06 implementation exposure after meaningful learner attempt.
- Competency claim: NONE — practice/learning evidence only; Week 1 competency requires fresh AI-0 gate.

---

## Notes

Day 1 learning/practice completed successfully.

This file records the exercise specification, completion status and corrected provenance.

Independent competency is not claimed from this artifact.
