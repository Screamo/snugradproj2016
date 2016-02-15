#include <linux/linkage.h>
#include <linux/kernel.h>

asmlinkage long sys_helloworld(void)
{
	printk(KERN_EMERG "HELLOWORLD\n");
	return 1;
}

