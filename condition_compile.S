	#定义临时无名字符串
	.section .rodata

.LC0:
	.string  "Hello 中国!"

.LC1:
	.string  "Hello World!"

#宏定义 重复打印a次
.macro INSERT_PRINT a
        .rept \a
        .print "This   is main function...."
        .endr
.endm


	.text
	.global main
	.type main @function
	
	#定义常量FLAG,DEBUG
	.set FLAG, 1
	.set DEBUG, 1

main:
	addi.d $sp, $sp, -8
	st.d  $ra, $sp, 0  #返回地址寄存器入栈

	#调试用途
.if	DEBUG == 1
	.print "This   is main function...."
	.err
	.fail 500
	#.error "error happened"
.endif 
	#调用宏定义
	INSERT_PRINT 3

	#条件编译
.if FLAG == 1
	la.local $r4, .LC0
.else
	la.local $r4, .LC1
.endif 
	bl	%plt(puts)

	
	#系统调用sys_exit
    	li.w $a7, 93              # exit syscall number
 	li.w $a0, 0
   	syscall 0x1               # syscall
	
	#寄存器ra出栈
	addi.d $sp, $sp, 8
	#函数返回
	jr $r1
	.size main, .-main
