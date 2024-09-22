#include <stdio.h>


static long* get_PC(void){

    unsigned long *val;
    //把当前函数的返回地址，写入val
    //当前函数的返回地址=调用该函数时的PC
    asm volatile ("move %0, $r1":"=r"(val));
    return val;
}


int main()
{
    long *ret = get_PC();
    //下面两种打印方式等价
    printf("PC val is: %lu\n", ret);
    printf("PC val is: %p\n", ret);


    //printf("PC val is: %lu\n", *ret);
    return 0;
}
