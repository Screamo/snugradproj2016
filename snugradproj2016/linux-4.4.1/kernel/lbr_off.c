#include <linux/linkage.h>
#include <linux/kernel.h>

#define LBR_LASTBRANCH0_FROM_IP 0x680
#define LBR_LASTBRANCH0_TO_IP	0x6C0

#define DECLARE_ARGS(low, high)	unsigned long low, high
#define EAX_EDX_RET(low, high)	"=a"(low), "=d"(high)
#define EAX_EDX_VAL(low, high)	((low) | (high) <<32)



asmlinkage long sys_lbr_off(void){
	unsigned int TOS;

	unsigned long lbr_FROM[16];
	unsigned long lbr_TO[16];

	unsigned int from, to;

	int i=0;

	DECLARE_ARGS(low, high);

	__asm__ __volatile(
	/* Turn LBR off */
	"movl	$0x1D9, %%ecx \n\t"
	"rdmsr \n\t"
	"btr	$0,	%%eax \n\t"
	"wrmsr \n\t"
	
	/* Get TOS value */
	"movl	$0x1C9,	%%ecx \n\t"
	"rdmsr \n\t"

	: "=a"(TOS)
	:
	: "memory"
	);

	/* Print TOS */
	printk(KERN_EMERG "TOS is pointing at %d\n",TOS);

	while(i<16){
		from	= LBR_LASTBRANCH0_FROM_IP + TOS;
		to	= LBR_LASTBRANCH0_TO_IP + TOS;

		/* Get lbr_FROM */
		__asm__ __volatile__(
		"rdmsr \n\t"
		: EAX_EDX_RET(low, high)
		: "c"(from)
		: "memory"
		);
		
		lbr_FROM[i] = EAX_EDX_VAL(low,high);

		
		/* Get lbr_TO */
		__asm__ __volatile__(
		"rdmsr \n\t"
		: EAX_EDX_RET(low, high)
		: "c"(to)
		: "memory"
		);
		
		lbr_TO[i] = EAX_EDX_VAL(low,high);


		/* Print lbr_FROM/TO */
		printk(KERN_EMERG "[%d] : FROM: %lX / TO: %lX \n",i, lbr_FROM[i], lbr_TO[i]);

		TOS = (TOS-1)%16;

		i=i+1;
	}		
	

	return 1;
}
