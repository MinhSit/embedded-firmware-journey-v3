#include "storage_demo.h"

extern int shared_value;

void peer_touch(void)
{
    ++shared_value;
}
