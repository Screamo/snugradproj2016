#include <stdio.h>


#define LBR_LASTBRANCH0_FROM_IP 0x680
#define LBR_LASTBRANCH0_TO_IP	0x6C0

#define DECLARE_ARGS(low, high)	unsigned long low, high
#define EAX_EDX_RET(low, high)	"=a"(low), "=d"(high)
#define EAX_EDX_VAL(low, high)	((low) | (high) <<32)

int main(void)
{
	unsigned int TOS;

	__asm__ __volatile__(
	"movl	$0x2,	%%eax \n\t"

	: "=a"(TOS)
	: 
	: 
	);

	printf( "TOS is pointing at %d\n",TOS);


	unsigned long lbr_FROM[16];
	unsigned long lbr_TO[16];


	unsigned int from = LBR_LASTBRANCH0_FROM_IP;
	unsigned int to = LBR_LASTBRANCH0_TO_IP;

	unsigned int i=0;

	DECLARE_ARGS(low, high);

	printf("%u\n",from);

	while(i<16){
		from = LBR_LASTBRANCH0_FROM_IP + i;

		/* Get lbr_FROM */
		__asm__ __volatile__(
		"movl	%%ecx,	%%eax \n\t"
		"movl	%%ecx,	%%edx \n\t"
		//"rdmsr \n\t"
		: EAX_EDX_RET(low, high)
		: "c"(from)
		: "memory"
		);
		
		lbr_FROM[i] = EAX_EDX_VAL(low,high);

		printf("[%X] : FROM: %lX / TO: \n\t",i, lbr_FROM[i]);

			
		i=i+1;
	}

	
	return 1;
}
