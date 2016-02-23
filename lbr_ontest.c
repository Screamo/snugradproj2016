#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>

int main(){
	syscall(400);
	printf("did it\n");
	return 1;
}
