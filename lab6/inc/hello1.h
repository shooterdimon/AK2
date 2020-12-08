#include <linux/ktime.h>

struct own_list_head {
    struct own_list_head *next;
    ktime_t start_time;
    ktime_t end_time;
};

int print_hello(uint count);
