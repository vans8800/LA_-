#include <stdio.h>
int balance=1000;
int atomic_sub(int a, int *b)
{
        int temp  = 0;
        __asm__ volatile(
        "ll.w  %0, %1 \n\t"  //temp =1000
        "sub.w %0, %0, %2\n\t" //temp - 100
        "sc.w  %0, %1\n\t" //*b = 900
        : "=&r" (temp), "+m" (*b)
        : "r" (a)
        : "memory");
        return 0;
}
int main()
{
        atomic_sub(100, &balance);
        printf("balance = %d\n", balance);
        return 0;
}

