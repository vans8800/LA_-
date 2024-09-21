#include <stdio.h>


static long* get_PC(void){

    unsigned long *val;

    asm volatile ("move %0, $r1":"=r"(val));
    return val;
}


int main()
{
    printf("PC val is: %ld\n",get_PC());
    printf("PC val is: %lu\n",get_PC());
    return 0;
}
