#include <stdio.h>

#include "storage_demo.h"

int shared_value = 10;
static int file_value = 20;
int zero_value;
static const char label[] = "W01D02";

static int next_id(void)
{
    static int id;
    ++id;
    return id;
}

int main(void)
{
    int automatic_value = 5;

    peer_touch();

    printf("%d %d %d %d %s\n",
           shared_value,
           file_value,
           zero_value,
           automatic_value + next_id(),
           label);

    return 0;
}
