#include <linux/init.h>
#include <linux/module.h>
#include <linux/types.h>
#include <hello1.h>

MODULE_AUTHOR("Zikratyi Dmytro, IV-81 group");
MODULE_LICENSE("Dual BSD/GPL");
MODULE_DESCRIPTION("AK-2.Labwork5.Building and Running modules");


static uint count = 1;
module_param(count, uint, 0);

static int initter(void){
    return print_hello(count);
}

static void exitter(void){
    printk(KERN_ALERT "Goodbye, cruel world\n");
}

module_init(initter);
module_exit(exitter);

