	.file	"mul.cpp"
	.section	.text.unlikely,"ax",@progbits
.LCOLDB0:
	.text
.LHOTB0:
	.globl	_Z6mul_19i
	.type	_Z6mul_19i, @function
_Z6mul_19i:
.LFB1044:
	.cfi_startproc
	imull	$19, %edi, %eax
	ret
	.cfi_endproc
.LFE1044:
	.size	_Z6mul_19i, .-_Z6mul_19i
	.section	.text.unlikely
.LCOLDE0:
	.text
.LHOTE0:
	.section	.text.unlikely
.LCOLDB1:
	.section	.text.startup,"ax",@progbits
.LHOTB1:
	.type	_GLOBAL__sub_I__Z6mul_19i, @function
_GLOBAL__sub_I__Z6mul_19i:
.LFB1046:
	.cfi_startproc
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$_ZStL8__ioinit, %edi
	call	_ZNSt8ios_base4InitC1Ev
	popq	%rcx
	.cfi_def_cfa_offset 8
	movl	$__dso_handle, %edx
	movl	$_ZStL8__ioinit, %esi
	movl	$_ZNSt8ios_base4InitD1Ev, %edi
	jmp	__cxa_atexit
	.cfi_endproc
.LFE1046:
	.size	_GLOBAL__sub_I__Z6mul_19i, .-_GLOBAL__sub_I__Z6mul_19i
	.section	.text.unlikely
.LCOLDE1:
	.section	.text.startup
.LHOTE1:
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I__Z6mul_19i
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.5) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
