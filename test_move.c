#include <stdio.h>


int main(){

 int ret = 0;
 int arrSrc[2]={10,20};
 printf("%p\t%d\n", arrSrc+1, *(arrSrc+1));
 asm("move %0, %1\n\t"
         :"=r"(ret)
         :"r" (arrSrc)
  );
   printf("ret is %p\n", ret);
	return 0;
}
