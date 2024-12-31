#include <stdio.h>


int main(){
	int dest =1 ;
	int add_value =2;
	int old_value;

	//printf("%p\t%p\t%p\n", &dest, &add_value, &old_value);
	asm volatile (
		"amadd.w %0, %1, %2 \n\t"
		: "=&r" (old_value)
		: "r" (add_value), "r"(&dest)
		: "memory"
	);

	 printf("old_value = %d\t dest=%d \n", old_value, dest);
	return 0;
}
