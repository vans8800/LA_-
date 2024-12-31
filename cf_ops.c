#include <stdio.h>


int main()
{
	register int ia  asm("r0") = 0;
	asm volatile(
		"li.w $r7, 0x1f\n\t"
		"movgr2fcsr $1, $7\n\t"
		"movfcsr2gr %0, $1\n\t"
		:"=r"(ia)
		:
		);
	
	printf("ia is 0x%x\n", ia);
	return 0;


#if 0 	


	//movgr2fcsr fcsr, rj //写浮点控制状态寄存器，fcsr = rj
	movfcsr2gr rd, fcsr //读浮点控制状态寄存器，rd = fcsr
	movfr2cf cd, fj //写条件标志寄存器，cd = fj[O]
	movcf2fr fd,cj //读条件标志寄存器，fd(0]= cj

	movgr2cf cd, rj  //写条件标志寄存器，cd = rj[O]
	movcf2gr rd, cj  //读条件标志寄存器，rd[0]= cj
#endif 
}
