	.file	"Lab#5_Menor_code.cpp"
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.section	.text._ZN7Point3DC2Ev,"axG",@progbits,_ZN7Point3DC5Ev,comdat
	.align 2
	.weak	_ZN7Point3DC2Ev
	.type	_ZN7Point3DC2Ev, @function
_ZN7Point3DC2Ev:
.LFB1106:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movl	$0, (%rax)
	movq	-8(%rbp), %rax
	movl	$0, 4(%rax)
	movq	-8(%rbp), %rax
	movl	$0, 8(%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1106:
	.size	_ZN7Point3DC2Ev, .-_ZN7Point3DC2Ev
	.weak	_ZN7Point3DC1Ev
	.set	_ZN7Point3DC1Ev,_ZN7Point3DC2Ev
	.section	.text._ZN7Point3DC2Eiii,"axG",@progbits,_ZN7Point3DC5Eiii,comdat
	.align 2
	.weak	_ZN7Point3DC2Eiii
	.type	_ZN7Point3DC2Eiii, @function
_ZN7Point3DC2Eiii:
.LFB1109:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movl	%edx, -16(%rbp)
	movl	%ecx, -20(%rbp)
	movq	-8(%rbp), %rax
	movl	-12(%rbp), %edx
	movl	%edx, (%rax)
	movq	-8(%rbp), %rax
	movl	-16(%rbp), %edx
	movl	%edx, 4(%rax)
	movq	-8(%rbp), %rax
	movl	-20(%rbp), %edx
	movl	%edx, 8(%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1109:
	.size	_ZN7Point3DC2Eiii, .-_ZN7Point3DC2Eiii
	.weak	_ZN7Point3DC1Eiii
	.set	_ZN7Point3DC1Eiii,_ZN7Point3DC2Eiii
	.section	.text._ZN7Point3D4getXEv,"axG",@progbits,_ZN7Point3D4getXEv,comdat
	.align 2
	.weak	_ZN7Point3D4getXEv
	.type	_ZN7Point3D4getXEv, @function
_ZN7Point3D4getXEv:
.LFB1111:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movl	(%rax), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1111:
	.size	_ZN7Point3D4getXEv, .-_ZN7Point3D4getXEv
	.section	.text._ZN7Point3D4getYEv,"axG",@progbits,_ZN7Point3D4getYEv,comdat
	.align 2
	.weak	_ZN7Point3D4getYEv
	.type	_ZN7Point3D4getYEv, @function
_ZN7Point3D4getYEv:
.LFB1112:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movl	4(%rax), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1112:
	.size	_ZN7Point3D4getYEv, .-_ZN7Point3D4getYEv
	.section	.text._ZN7Point3D4getZEv,"axG",@progbits,_ZN7Point3D4getZEv,comdat
	.align 2
	.weak	_ZN7Point3D4getZEv
	.type	_ZN7Point3D4getZEv, @function
_ZN7Point3D4getZEv:
.LFB1113:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movl	8(%rax), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1113:
	.size	_ZN7Point3D4getZEv, .-_ZN7Point3D4getZEv
	.section	.rodata
.LC0:
	.string	"%i %i %i"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1114:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$88, %rsp
	.cfi_offset 3, -24
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	movl	$12, %edi
	call	_Znwm
	movq	%rax, %rbx
	movq	%rbx, %rdi
	call	_ZN7Point3DC1Ev
	movq	%rbx, -40(%rbp)
	movl	$12, %edi
	call	_Znwm
	movq	%rax, %rbx
	movq	%rbx, %rdi
	call	_ZN7Point3DC1Ev
	movq	%rbx, -32(%rbp)
	leaq	-72(%rbp), %rax
	movq	%rax, %rsi
	movl	$_ZSt3cin, %edi
	call	_ZNSirsERi
	movl	$0, -52(%rbp)
.L15:
	movl	-72(%rbp), %eax
	cmpl	%eax, -52(%rbp)
	jge	.L10
	leaq	-68(%rbp), %rax
	movq	%rax, %rsi
	movl	$_ZSt3cin, %edi
	call	_ZNSirsERi
	movl	$0, -48(%rbp)
.L14:
	movl	-68(%rbp), %eax
	cmpl	%eax, -48(%rbp)
	jge	.L11
	cmpl	$0, -48(%rbp)
	jne	.L12
	leaq	-56(%rbp), %rcx
	leaq	-60(%rbp), %rdx
	leaq	-64(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	scanf
	movl	$12, %edi
	call	_Znwm
	movq	%rax, %rbx
	movl	-56(%rbp), %ecx
	movl	-60(%rbp), %edx
	movl	-64(%rbp), %eax
	movl	%eax, %esi
	movq	%rbx, %rdi
	call	_ZN7Point3DC1Eiii
	movq	%rbx, -40(%rbp)
	jmp	.L13
.L12:
	leaq	-56(%rbp), %rcx
	leaq	-60(%rbp), %rdx
	leaq	-64(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	scanf
	movl	$12, %edi
	call	_Znwm
	movq	%rax, %rbx
	movl	-56(%rbp), %ecx
	movl	-60(%rbp), %edx
	movl	-64(%rbp), %eax
	movl	%eax, %esi
	movq	%rbx, %rdi
	call	_ZN7Point3DC1Eiii
	movq	%rbx, -32(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN7Point3D4getXEv
	movl	%eax, %ebx
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN7Point3D4getXEv
	subl	%eax, %ebx
	movl	%ebx, %eax
	movl	%eax, %edi
	call	_ZSt3absIiEN9__gnu_cxx11__enable_ifIXsrSt12__is_integerIT_E7__valueEdE6__typeES3_
	movsd	%xmm0, -88(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN7Point3D4getYEv
	movl	%eax, %ebx
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN7Point3D4getYEv
	subl	%eax, %ebx
	movl	%ebx, %eax
	movl	%eax, %edi
	call	_ZSt3absIiEN9__gnu_cxx11__enable_ifIXsrSt12__is_integerIT_E7__valueEdE6__typeES3_
	movapd	%xmm0, %xmm1
	addsd	-88(%rbp), %xmm1
	movsd	%xmm1, -88(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN7Point3D4getZEv
	movl	%eax, %ebx
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN7Point3D4getZEv
	subl	%eax, %ebx
	movl	%ebx, %eax
	movl	%eax, %edi
	call	_ZSt3absIiEN9__gnu_cxx11__enable_ifIXsrSt12__is_integerIT_E7__valueEdE6__typeES3_
	addsd	-88(%rbp), %xmm0
	cvttsd2si	%xmm0, %eax
	movl	%eax, -44(%rbp)
	movq	-32(%rbp), %rax
	movq	%rax, -40(%rbp)
	movl	-44(%rbp), %eax
	movl	%eax, %esi
	movl	$_ZSt4cout, %edi
	call	_ZNSolsEi
	movl	$10, %esi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c
.L13:
	addl	$1, -48(%rbp)
	jmp	.L14
.L11:
	addl	$1, -52(%rbp)
	jmp	.L15
.L10:
	movl	$0, %eax
	movq	-24(%rbp), %rsi
	xorq	%fs:40, %rsi
	je	.L17
	call	__stack_chk_fail
.L17:
	addq	$88, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1114:
	.size	main, .-main
	.section	.text._ZSt3absIiEN9__gnu_cxx11__enable_ifIXsrSt12__is_integerIT_E7__valueEdE6__typeES3_,"axG",@progbits,_ZSt3absIiEN9__gnu_cxx11__enable_ifIXsrSt12__is_integerIT_E7__valueEdE6__typeES3_,comdat
	.weak	_ZSt3absIiEN9__gnu_cxx11__enable_ifIXsrSt12__is_integerIT_E7__valueEdE6__typeES3_
	.type	_ZSt3absIiEN9__gnu_cxx11__enable_ifIXsrSt12__is_integerIT_E7__valueEdE6__typeES3_, @function
_ZSt3absIiEN9__gnu_cxx11__enable_ifIXsrSt12__is_integerIT_E7__valueEdE6__typeES3_:
.LFB1115:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	pxor	%xmm0, %xmm0
	cvtsi2sd	-4(%rbp), %xmm0
	movsd	.LC1(%rip), %xmm1
	andpd	%xmm1, %xmm0
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1115:
	.size	_ZSt3absIiEN9__gnu_cxx11__enable_ifIXsrSt12__is_integerIT_E7__valueEdE6__typeES3_, .-_ZSt3absIiEN9__gnu_cxx11__enable_ifIXsrSt12__is_integerIT_E7__valueEdE6__typeES3_
	.text
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB1117:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	cmpl	$1, -4(%rbp)
	jne	.L22
	cmpl	$65535, -8(%rbp)
	jne	.L22
	movl	$_ZStL8__ioinit, %edi
	call	_ZNSt8ios_base4InitC1Ev
	movl	$__dso_handle, %edx
	movl	$_ZStL8__ioinit, %esi
	movl	$_ZNSt8ios_base4InitD1Ev, %edi
	call	__cxa_atexit
.L22:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1117:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I_main, @function
_GLOBAL__sub_I_main:
.LFB1118:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$65535, %esi
	movl	$1, %edi
	call	_Z41__static_initialization_and_destruction_0ii
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1118:
	.size	_GLOBAL__sub_I_main, .-_GLOBAL__sub_I_main
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I_main
	.section	.rodata
	.align 16
.LC1:
	.long	4294967295
	.long	2147483647
	.long	0
	.long	0
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.5) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
