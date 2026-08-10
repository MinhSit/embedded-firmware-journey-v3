#ifndef C_EXERCISES_01_H
#define C_EXERCISES_01_H

#include <stdbool.h>
#include <stddef.h>

typedef int (*int_transform_fn)(int value);

/*
 * E01
 * Swap the values referenced by a and b.
 *
 * Return:
 *   true  - success
 *   false - a == NULL or b == NULL
 */
bool swap_int(int *a, int *b);

/*
 * E02
 * Sum len integers.
 *
 * Contract:
 *   - out_sum must not be NULL.
 *   - arr may be NULL only when len == 0.
 *   - len == 0 produces sum == 0.
 */
bool sum_ints(const int *arr, size_t len, long *out_sum);

/*
 * E03
 * Find maximum value.
 *
 * Contract:
 *   - arr != NULL
 *   - out_max != NULL
 *   - len > 0
 */
bool max_int(const int *arr, size_t len, int *out_max);

/*
 * E04
 * Reverse array in-place.
 *
 * Contract:
 *   - arr may be NULL only when len == 0.
 */
bool reverse_ints(int *arr, size_t len);

/*
 * E05
 * Return pointer to first matching element.
 *
 * Return NULL if:
 *   - target is not found
 *   - input is invalid
 */
const int *find_first(const int *arr, size_t len, int target);

/*
 * E06
 * Change the pointer stored in *slot.
 *
 * Contract:
 *   - slot must not be NULL.
 *   - target itself may be NULL.
 */
bool retarget_pointer(int **slot, int *target);

/*
 * E07
 * Apply fn() to every element in-place.
 *
 * Contract:
 *   - fn must not be NULL.
 *   - arr may be NULL only when len == 0.
 */
bool transform_ints(int *arr, size_t len, int_transform_fn fn);

#endif