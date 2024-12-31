#include <stdio.h>

int main()
{
	register int a asm("a0") =  0x11223344 ;
	register int c = 0;
	asm volatile(
	        "revb.2w $r5, %1    \n\t"
		"move %0, $r5 \n\t"
	  	:"=r"(c)	
		:"r"(a)
		);

		printf("c is 0x%x\n",c);
			return 0;
}
