#include <linux/module.h>	/* Needed by all modules */
#include <linux/kernel.h>	/* Needed for KERN_INFO */
#include <linux/init.h>		/* Needed for the macros */

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Maximilian Gerhardt");
MODULE_DESCRIPTION("Basic kernel module for tutorial");

static int __init hello_2_init(void)
{
	printk(KERN_INFO "Hello, world! We're inside the Omega2's kernel.\n");
	return 0;
}

static void __exit hello_2_exit(void)
{
	printk(KERN_INFO "Goodbye, world!\n");
}

module_init(hello_2_init);
module_exit(hello_2_exit);