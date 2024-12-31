#include <stdio.h>

int main(){
//$a0 or $a0 all propitious
	register int a asm("a0") = 1;
	register int b asm("a1") = 2;
	asm volatile ("addi.w %0, %1, 0xf\n\t"
		       :"=r"(a)
		       :"r"(b));
	printf("The result is %d\n", a);
	
}

