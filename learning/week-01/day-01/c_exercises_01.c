#include "c_exercises_01.h"

bool swap_int(int *a, int *b)
{
    /* TODO E01 */
    if(a == NULL || b == NULL) return false;
    int temp = *a;
    *a = *b;
    *b = temp;
    return true;
}

bool sum_ints(const int *arr, size_t len, long *out_sum)
{
    /* TODO E02 */
    if((arr == NULL && len != 0U) || out_sum == NULL) return false;
    if(len == 0U && arr == NULL){
        *out_sum = 0;
        return true;
    }
    long sum = 0;
    for(size_t i = 0; i < len; i++){
        sum += arr[i]; // hoặc dùng sum += *(arr + i)
    }
    *out_sum = sum;
    return true;
}

bool max_int(const int *arr, size_t len, int *out_max)
{
    /* TODO E03 */
    if(arr == NULL || len == 0U || out_max == NULL) return false;
    int max = arr[0];
    for(size_t i = 1; i < len; i++){
        if(arr[i] > max) max = arr[i]; // có thể dùng *(arr + i) thay cho arr[i]
    }
    *out_max = max;
    return true;
}

bool reverse_ints(int *arr, size_t len)
{
    /* TODO E04 */
    if(arr == NULL && len != 0U) return false;
    if(len == 0U || len == 1U) return true;
    for(size_t i = 0; i < len / 2; i++){
        int temp_left = arr[i];
        arr[i] = arr[len - i - 1U];
        arr[len - i - 1U] = temp_left;
    }
    return true;
}

const int *find_first(const int *arr, size_t len, int target)
{
    /* TODO E05 */
    if(arr == NULL || len == 0U) return NULL;
    for(size_t i = 0; i < len; i++){
        if(arr[i] == target) return arr + i;
    }
    return NULL;
}

bool retarget_pointer(int **slot, int *target)
{
    /* TODO E06 */
    if(slot == NULL) return false;
    *slot = target;
    return true;
}

bool transform_ints(int *arr, size_t len, int_transform_fn fn)
{
    /* TODO E07 */
    if((arr == NULL && len != 0U) || fn == NULL) return false;
    if(arr == NULL && len == 0U) return true;
    for(size_t i = 0; i < len; i++) arr[i] = fn(arr[i]);
    return true;
}