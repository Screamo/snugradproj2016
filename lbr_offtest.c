#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>

int main(){
	syscall(401);
	printf("did it off\n");
	return 1;
}
