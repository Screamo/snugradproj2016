#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>

int main(){
	syscall(402);
	return 0;
}
