#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>
#include <hello1.h>
#include <linux/slab.h>

MODULE_AUTHOR("Zikratyi Dmytro, IV-81 group");
MODULE_LICENSE("Dual BSD/GPL");
MODULE_DESCRIPTION("AK-2.Labwork6.Allocating Memory");

static struct own_list_head *head;

int print_hello(uint count)
{
	int i;
	struct own_list_head *tempHeadA;
	struct own_list_head *tempHeadB;

	head = kmalloc(sizeof(struct own_list_head *), GFP_KERNEL);
	tempHeadA = head;
	if (count == 0) {
		pr_warn("Warning!!!\nValue is 0\n");
		return 0;
	} else if (count >= 5 && count <= 10) {
		pr_warn("Warning!!!\nValue is in range from 5 to 10\n");
	} else if (count > 10) {
		pr_err("Error!\nValue is more than 10");
		return -EINVAL;
	}
	for (i = 0; i < count; i++) {
		tempHeadA->next = kmalloc(sizeof(struct own_list_head *), GFP_KERNEL);
		tempHeadA->start_time = ktime_get();
		pr_info("Hello, world!\n");
		tempHeadA->end_time = ktime_get();
		tempHeadB = tempHeadA;
		tempHeadA = tempHeadA->next;
	}
	kfree(tempHeadB->next);
	tempHeadB->next = NULL;
	return 0;
}
EXPORT_SYMBOL(print_hello);

static int __init initter(void)
{
	pr_info("Module hello1 init");
	return 0;
}

static void __exit exitter(void)
{
	struct own_list_head *tempA = head;
	struct own_list_head *tempB = tempA;

	while (tempA != NULL) {
		pr_info("Time was spend %lld ns", tempA->end_time - tempA->start_time);
		tempB = tempA;
		tempA = tempB->next;
		kfree(tempB);
	}
	pr_info("Module hello1 exit");
}

module_init(initter);
module_exit(exitter);

