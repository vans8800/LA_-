#include <stdio.h>


//calc: 2+2<<3
int main(){

	int a=2, b=3,c=0;
			//"sll.d %[a], %[a], %[b]\n\t"
			//"addi.d %[c], %1, 2\n\t"	
	asm volatile(
			"sll.d %[a], %[a], %[b]\n\t"
			"addi.d %[c], %1, 2\n\t"
			//"alsl.d %[c], %[a], %[a], 3"
			:[c]"=r"(c)
			:[a]"r"(a), [b]"r"(b)
			//:[a]"r"(a)
	);
	printf("result is %d\n", c);
	return 0;
}
