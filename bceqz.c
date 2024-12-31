#include <stdio.h>



void test_fcmp1()
{
	register float  fa  asm("f0") = 1.0;
	register float  fb  asm("f1") = 2.0;
	register int ic asm("r4");


	//int c = a < b : 1 : 0
	//if f0 < f1  fcc0 = 1 else fcc0 = 0
	asm volatile (
		"li.w $r4, 0 \n\t"
		"fcmp.slt.s $fcc0, $f0, $f1 \n\t" 
		"bceqz $fcc0, 0x4 \n\t"
		"li.w $r4, 1 \n\t"
		"nop \n\t"
		);


	printf("ic  is ret %d\n", ic);

}

void test_fcmp2 ()
{
	float fv = 0.0;
	register float  fa asm("f0") = 10.0;
	register float  fb asm("f1") = 20.0;
	//float fv = a < b ? fa: fb
	asm volatile (
		"fcmp.slt.s $fcc0, $f0, $f1 \n\t"
		"bceqz      $fcc0, 0x4 \n\t"
		"fmov.s %0, $f0\n\t"
		"fmov.s %0, $f1\n\t"
		:"=f"(fv)
		:"f"(fa), "f"(fb)
		:
	);
	printf("fv is %f\n", fv);

}


int main ()
{
	test_fcmp1();
}	
