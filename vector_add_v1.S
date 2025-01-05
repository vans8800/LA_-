#file: vectoradd.S
#function: void vector_add(int* a, int* b, int* c)


        .text
        .align 2
        .global vector_add
        .type vector_add,@function

vector_add:


       li.w  $t0, 0x0    //for loop var
       li.w  $t1, 0x8
       div.w $t2, $a3, $t1   //商
       mod.w $t3, $a3, $t1   //余


LC0:
       xvld   $xr1, $a0, 0       // 加载数组 a[] 中的 8 组整形值到向量寄存器 x1
       xvld   $xr2, $a1, 0       // 加载数组 b[] 中的 8 组整形值到向量寄存器 x2
       xvadd.w $xr3, $xr1, $xr2  // 实现 a[i...i+8] + b[i...i+8], 将结果存入寄存器 x3
       xvst   $xr3, $a2, 0       // x3 数据写回 c[i...i+8], t4 寄存器的值指向 c[i]

       addi.d $a0, $a0, 32       // 数组 a[] + 32, 即指向 a[i + 9]
       addi.d $a1, $a1, 32       // 数组 b[] + 32, 注意：原书中此处是 addi.d     a1, a2, 32
       addi.d $a2, $a2, 32       // 数组 c[] + 32
       addi.d $t0, $t0, 1        //t0=t0+1 主要和商比较
       bne $t0, $t2, LC0   //# 判断若 for () 没有结束，跳转到L，继续执行


      #处理余数部分
      li.w $t1, 0x4
      li.w $t0, 0x1
      div.w $t4, $t3, $t1   //商
      mod.w $t5, $t3, $t1   //余

      beq $t4, $t0, LC1 #商大于1


      vld $vr4, $a0 ,0
      vld $vr5, $a1 ,0
      vadd.w $vr6, $vr4, $vr5

      #最后余数个计算结果存入
      #vpickve2gr.w $t6, $vr6, $t5
      vst $vr6, $a2, 0



LC1:
      vld $vr4, $a0 ,0
      vld $vr5, $a1 ,0
      vadd.w $vr6, $vr4, $vr5
      vst    $vr6, $a2, 0

      addi.d $a0, $a0, 16       // 数组 a[] + 32, 即指向 a[i + 9]
      addi.d $a1, $a1, 16       // 数组 b[] + 32, 注意：原书中此处是 addi.d     a1, a2, 32
      addi.d $a2, $a2, 16       // 数组 c[] + 32





      jr $ra

