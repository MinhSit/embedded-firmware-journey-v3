#include <stdbool.h>
#include <stddef.h>

bool get_max_value(const int *values, size_t count, int *out_max)
{
    // Kiểm tra tính hợp lệ của tất cả đầu vào
    if (values == NULL || count == 0 || out_max == NULL) {
        return false;
    }

    int max = values[0];
    for (size_t i = 1; i < count; ++i) {
        if (values[i] > max) {
            max = values[i];
        }
    }

    *out_max = max;
    return true;
}