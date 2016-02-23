#include <linux/linkage.h>
#include <linux/kernel.h>

/* sys_helloworld for testing */

asmlinkage long sys_helloworld(void){
	printk(KERN_EMERG "Hello, world!\n");
	return 1;
}
