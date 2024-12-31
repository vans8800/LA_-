	.section .rodata
.LC0:
	.string "I am here"

	
	.text
	.global main

main:
	/*
	◦ fcmp.slt.s
	▪ if ($f23 < $f24) $fcc0 = 1
	▪ else $fcc0 = 0
	◦ bceqz
	▪ if ($fcc0 == 0) jump .L128
	*/

    	li.d $a0, 50       # $a0 = 5 
    	li.d $a1, 10       # $a1 = 10


	movgr2fr.d $ft0, $a0
	movgr2fr.d $ft1, $a1

	fcmp.slt.d $fcc0, $ft0, $ft1 
	bceqz $fcc0, .L128
	nop
.L128:
	nop
	
	la.local $r4, .LC0
	bl	%plt(puts)


        li.w $a7, 93       # exit syscall number
        li.w $a0, 0 
        syscall 0x1        # syscall 

	jr $r1
	.size main, .-main
