	.file	"temp_conv.c"
	.text
	.align	2
	.globl	convert
	.type	convert, @function
convert:
.LFB0 = .
	.cfi_startproc
	addi.d	$r3,$r3,-48
	.cfi_def_cfa_offset 48
	st.d	$r22,$r3,40
	.cfi_offset 22, -8
	addi.d	$r22,$r3,48
	.cfi_def_cfa 22, 0
	or	$r12,$r4,$r0
	slli.w	$r12,$r12,0
	st.w	$r12,$r22,-36
	ld.w	$r12,$r22,-36
	movgr2fr.w	$f0,$r12
	ffint.d.w	$f1,$f0
	la.local	$r12,.LC0
	fld.d	$f0,$r12,0
	fsub.d	$f1,$f1,$f0
	la.local	$r12,.LC1
	fld.d	$f0,$r12,0
	fdiv.d	$f0,$f1,$f0
	fcvt.s.d	$f0,$f0
	fst.s	$f0,$r22,-20
	fld.s	$f0,$r22,-20
	ld.d	$r22,$r3,40
	.cfi_restore 22
	addi.d	$r3,$r3,48
	.cfi_def_cfa_register 3
	jr	$r1
	.cfi_endproc
.LFE0:
	.size	convert, .-convert
	.section	.rodata
	.align	3
.LC2:
	.ascii	"    Temperature Conversion Chart\000"
	.align	3
.LC3:
	.ascii	"Fahrenheit  Celsius\000"
	.align	3
.LC4:
	.ascii	"    %d      %5.2f\012\000"
	.text
	.align	2
	.globl	main
	.type	main, @function
main:
.LFB1 = .
	.cfi_startproc
	addi.d	$r3,$r3,-32
	.cfi_def_cfa_offset 32
	st.d	$r1,$r3,24
	st.d	$r22,$r3,16
	.cfi_offset 1, -8
	.cfi_offset 22, -16
	addi.d	$r22,$r3,32
	.cfi_def_cfa 22, 0
	st.w	$r0,$r22,-20
	la.local	$r4,.LC2
	bl	%plt(puts)
	la.local	$r4,.LC3
	bl	%plt(puts)
	st.w	$r0,$r22,-20
	b	.L4
.L5:
	ld.w	$r12,$r22,-20
	or	$r4,$r12,$r0
	bl	convert
	fst.s	$f0,$r22,-24
	fld.s	$f0,$r22,-24
	fcvt.d.s	$f0,$f0
	ld.w	$r12,$r22,-20
	movfr2gr.d	$r6,$f0
	or	$r5,$r12,$r0
	la.local	$r4,.LC4
	bl	%plt(printf)
	ld.w	$r12,$r22,-20
	addi.w	$r12,$r12,10
	st.w	$r12,$r22,-20
.L4:
	ld.w	$r12,$r22,-20
	or	$r13,$r12,$r0
	addi.w	$r12,$r0,229			# 0xe5
	ble	$r13,$r12,.L5
	or	$r12,$r0,$r0
	or	$r4,$r12,$r0
	ld.d	$r1,$r3,24
	.cfi_restore 1
	ld.d	$r22,$r3,16
	.cfi_restore 22
	addi.d	$r3,$r3,32
	.cfi_def_cfa_register 3
	jr	$r1
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.section	.rodata
	.align	3
.LC0:
	.word	0
	.word	1077936128
	.align	3
.LC1:
	.word	3435973837
	.word	1073532108
	.ident	"GCC: (GNU) 8.3.0 20190222 (Loongson 8.3.0-35 vec)"
	.section	.note.GNU-stack,"",@progbits
