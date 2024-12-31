.data
.LC0:
	.ascii "test\0"
	.text
	.align 2
	.globl main
	.type main, @function
main:
	#addi.d $sp, $sp, -32
	#st.d $ra, $sp, 24
	#st.d $fp, $sp, 16
	#addi.d $fp, $sp, 32
	st.d $ra, $sp, -8	#保存返回地址
	st.d $fp, $sp, -16	#保存调用者的栈帧指针
	addi.d $fp, $sp, 0	#设置新的栈帧指针
	addi.d $sp, $sp, -16	#入栈，为栈帧分配16字节空间

	or $t0, $a0, $zero
	st.d $a1, $fp, -32
	slli.w $t0, $t0, 0
	st.w $t0, $fp, -20
	la.local $a0, .LC0
	bl %plt(puts)
	or $t0, $zero, $zero
	or $a0, $t0, $zero
	
	#ld.d $ra, $sp, 24
	#ld.d $fp, $sp, 16
	#addi.d $sp, $sp, 32
	addi.d $sp, $sp, 16	#出栈,恢复原来的栈指针
	ld.d $ra, $sp, -8	#恢复返回地址
	ld.d $fp, $sp, -16	#恢复栈帧指针
	jr $ra
	.size main, .-main
	.section .note.GNU-stack, "", @progbits
