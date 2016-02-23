
#include <stdio.h>

int main(void){
	int a = 10;
	__asm__ __volatile__(
		"mov $0xff, %%ecx\n\t"
		"btr $0, %%ecx\n\t"
		"mov %%ecx, %0"
	:	"=d"(a)
	:
	:
	);
	printf("You've got %d",a);
	return 1;
}


/* Successed example 1.

#include <stdio.h>

int main(void){
	int a = 10;
	__asm__ __volatile__(
		"mov $20, %0"
	:	"=d"(a)
	:
	:
	);
	printf("You've got %d",a);
	return 1;
}

*/

/* Successed example 2.

#include <stdio.h>

int main(void){
	int a = 10;
	__asm__ __volatile__(
		"mov $30, %%ecx\n\t"
		"mov %%ecx, %0"
	:	"=d"(a)
	:
	:
	);
	printf("You've got %d",a);
	return 1;
}

*/
