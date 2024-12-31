#include <stdio.h>

int main()
{
	register int a asm("a0") =  0x0fffa ;
	register int c = 0;
	asm volatile(
	        "ext.w.h %0, %1\n\t"
		:"=r"(c)
		:"r"(a)
	);
	printf("c is 0x%x\n", c);
	return 0;

}
