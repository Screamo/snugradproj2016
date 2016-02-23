#include <linux/linkage.h>
#include <linux/kernel.h>

asmlinkage long sys_lbr_on(void){

	__asm__ __volatile__(
		"mov $0x1D9, %%ecx\n\t"
		"rdmsr\n\t"
		"bts $0, %%eax\n\t"
		"wrmsr\n\t"
		:
		:
		:"memory"
	);

	printk(KERN_EMERG "You called sys_lbr_on, msr no. 1D9\n");

	return 1;
}	
