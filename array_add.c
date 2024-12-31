#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ARR_LEN 10000

typedef u_int32_t uint32_t;
static inline uint32_t read_time(void)
{
    uint32_t a = 0, id = 0;
    asm volatile ( "rdtimel.w  %0, %1" : "=r"(a), "=r"(id) :: "memory" );
    return a;
}


int main()
{
	int start=0, end=0;
	double  duration;
	int a[ARR_LEN], b[ARR_LEN], c[ARR_LEN]={0};
	srand((unsigned)time(NULL));
	for(int i =0; i < ARR_LEN; i++){
		a[i] = rand()%ARR_LEN+1;
		b[i] = rand()%ARR_LEN+1;
	}

#if 0
    	start = read_time();
	for (int i = 0; i < ARR_LEN; i++)
		c[i] = a[i] + b[i];
    	end = read_time();
    	duration = end - start;
#endif

	printf("%p\t%p\t%p\n", a, b ,c);
    	start = read_time();
	asm volatile(
			"li.w   $t0, 0x0	\n\t"   //for loop var
			"li.w	$t1, 10000	\n\t"	//for loop var
			"ld.d   $t2, %[a]	\n\t"	//load addr(a);
			"ld.d   $t3, %[b]	\n\t"   //load addr(b);
			"ld.d   $t4, %[c]	\n\t"   //load addr(c);

		"L:			\n\t"
			"xvld	$xr1, $t2, 0	\n\t"	// 加载数组 a[] 中的 8 组整形值到向量寄存器 x1
			"xvld	$xr2, $t3, 0	\n\t"	// 加载数组 b[] 中的 8 组整形值到向量寄存器 x2
			"xvadd.w $xr3, $xr1, $xr2	\n\t"	// 实现 a[i...i+8] + b[i...i+8], 将结果存入寄存器 x3
			"xvst	$xr3, $t4, 0	\n\t"	// x3 数据写回 c[i...i+8], t4 寄存器的值指向 c[i]
			
			"addi.d	$t2, $t2, 32	\n\t"	// 数组 a[] + 32, 即指向 a[i + 9]
			"addi.d	$t3, $t3, 32	\n\t"	// 数组 b[] + 32, 注意：原书中此处是 addi.d	a1, a2, 32
			"addi.d	$t4, $t4, 32	\n\t"	// 数组 b[] + 32
			"addi.d $t0, $t0, 8	\n\t"   //t0=t0+8
			"bne $t0, $t1, L \n\t"	//# 判断若 for () 没有结束，跳转到L，继续执行
	:[c]"+m"(c)
	:[a]"m"(a), [b]"m"(b)
	:"memory");

    	end = read_time();
    	duration = end - start;
	
        printf("[performance test]\n"
       	        "org cycles: %g\n",
                duration);
	return 0;
}
