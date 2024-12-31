#include <stdio.h>

int main()
{
	unsigned int c = 0;
	register int a asm("$a0") = -1;
	register unsigned int b asm("$a1") = 2;

	asm volatile("add.w %0,%1,%2\n\t"
			:"=r"(c)
			:"r"(b), "r"(a));
	printf("tell me the result is %d\n", c);
	printf("tell me the result is %u\n", c);

}
