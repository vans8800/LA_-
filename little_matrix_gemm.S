#文件 add.S
#接口定义 int add_f(int , int , int ,int)
#功能定义: return (int+int+int+int)

	.text
	.align 2
	.global add_f
	.type add_f,@function

add_f:
	add.w	$a0, $a0, $a1
	add.w	$a0, $a0, $a2
	add.w	$a0, $a0, $a3
	jr $ra
	.size add_f, .-add_f
	
