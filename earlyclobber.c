#include <stdio.h>

void test5(void) {
    int in = 1;
    int out;
    __asm__ (
            "add.w %[out], %[in], $zero;" /* out = in */
            "addi.w %[out], %[out], 1;" /* out++ */
            "add.w %[out], %[in], $zero;" /* out = in */
            "addi.w %[out], %[out], 1;" /* out++ */
            : [out] "+r" (out)
	     // : [out] "=&r" (out) 效果相同
            : [in] "r" (in)
            :
            );
    if (out != 2)
        printf("error\n");
}



int main()
{
	//参考: https://github.com/foxsen/loongarch-assembly/blob/main/inline-assembly.md
	test5();
	return 0;
}
