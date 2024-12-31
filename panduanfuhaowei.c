#include <stdio.h>

int main()
{
	register int a asm("a0") =  0x7ffffffe ;
	register int b asm("a1") =  2 ;
	register int c = 0;
	asm volatile(
	        "add.w $r5, %1, %2\n\t"
		"srai.w $r5, $r5, 31 \n\t"		       
		"andi %0, $r5, 1  \n\t"
		:"=r"(c)
		:"r"(a), "r"(b)
	);
	printf("c is %d\n", c);
	return 0;

}
