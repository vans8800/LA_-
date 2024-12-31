#include <stdio.h>

int main(){
	int a =10;
	int ret =0 ;
	asm volatile(
		".set push, \n\t"
		"addi.w %[ret], %[a], %2 \n\t"
		".set pop,\n\t"
		:[ret]"=r"(ret)
		:[a]"r"(a), "I"(100)		
	);
	printf("ret is %d\n", ret);
	return 0;
}
