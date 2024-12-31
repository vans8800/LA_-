
	.section .text
	.align 2
	.globl myadd
	.type myadd, %function 

myadd:
	add.d $v0, $a0,$a1
	jirl  $zero, $ra, 0
