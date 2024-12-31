#include <stdio.h>

int main()
{
	int a = 10;
	int *p = NULL;

	asm ("move %0, %1 \n\t"
	   :"=r"(p)
   	   :"r"(&a)
	   :"$t1"	   
	);
	printf("addr=%p\t%p\n", &a, p);
}
