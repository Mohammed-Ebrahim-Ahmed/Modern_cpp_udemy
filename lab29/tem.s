	.file	"tem.cpp"
	.text
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC2:
	.ascii " \0"
.LC3:
	.ascii "int sum = \0"
.LC7:
	.ascii "float sum = \0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB2563:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$96, %rsp
	.seh_stackalloc	96
	.seh_endprologue
	call	__main
	movl	$3, %edx
	movl	$2, %ecx
	call	_Z3AddIiET_S0_S0_
	movl	%eax, -4(%rbp)
	movsd	.LC0(%rip), %xmm0
	movq	.LC1(%rip), %rax
	movapd	%xmm0, %xmm1
	movq	%rax, %xmm0
	call	_Z3AddIdET_S0_S0_
	cvtsd2ss	%xmm0, %xmm0
	movss	%xmm0, -8(%rbp)
	movl	-4(%rbp), %eax
	movl	%eax, %edx
	movq	.refptr._ZSt4cout(%rip), %rax
	movq	%rax, %rcx
	call	_ZNSolsEi
	movq	%rax, %rcx
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movss	-8(%rbp), %xmm0
	movaps	%xmm0, %xmm1
	movq	%rax, %rcx
	call	_ZNSolsEf
	movq	%rax, %rcx
	movq	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_(%rip), %rax
	movq	%rax, %rdx
	call	_ZNSolsEPFRSoS_E
	movl	$1, -28(%rbp)
	movl	$2, -24(%rbp)
	movl	$3, -20(%rbp)
	leaq	-28(%rbp), %rax
	movl	$3, %edx
	movq	%rax, %rcx
	call	_Z8ArraySumIiET_PKS0_y
	movl	%eax, -12(%rbp)
	leaq	.LC3(%rip), %rax
	movq	%rax, %rdx
	movq	.refptr._ZSt4cout(%rip), %rax
	movq	%rax, %rcx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movq	%rax, %rcx
	movl	-12(%rbp), %eax
	movl	%eax, %edx
	call	_ZNSolsEi
	movq	%rax, %rcx
	movq	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_(%rip), %rax
	movq	%rax, %rdx
	call	_ZNSolsEPFRSoS_E
	movss	.LC4(%rip), %xmm0
	movss	%xmm0, -40(%rbp)
	movss	.LC5(%rip), %xmm0
	movss	%xmm0, -36(%rbp)
	movss	.LC6(%rip), %xmm0
	movss	%xmm0, -32(%rbp)
	leaq	-40(%rbp), %rax
	movl	$3, %edx
	movq	%rax, %rcx
	call	_Z8ArraySumIfET_PKS0_y
	movd	%xmm0, %eax
	movl	%eax, -16(%rbp)
	leaq	.LC7(%rip), %rax
	movq	%rax, %rdx
	movq	.refptr._ZSt4cout(%rip), %rax
	movq	%rax, %rcx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movss	-16(%rbp), %xmm0
	movaps	%xmm0, %xmm1
	movq	%rax, %rcx
	call	_ZNSolsEf
	movq	%rax, %rcx
	movq	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_(%rip), %rax
	movq	%rax, %rdx
	call	_ZNSolsEPFRSoS_E
	leaq	-28(%rbp), %rax
	movl	$3, %edx
	movq	%rax, %rcx
	call	_Z3MaxIiET_PKS0_y
	movl	%eax, %edx
	movq	.refptr._ZSt4cout(%rip), %rax
	movq	%rax, %rcx
	call	_ZNSolsEi
	movq	%rax, %rcx
	movq	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_(%rip), %rax
	movq	%rax, %rdx
	call	_ZNSolsEPFRSoS_E
	leaq	-40(%rbp), %rax
	movl	$3, %edx
	movq	%rax, %rcx
	call	_Z3MaxIfET_PKS0_y
	movd	%xmm0, %eax
	movd	%eax, %xmm1
	movq	.refptr._ZSt4cout(%rip), %rax
	movq	%rax, %rcx
	call	_ZNSolsEf
	movq	%rax, %rcx
	movq	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_(%rip), %rax
	movq	%rax, %rdx
	call	_ZNSolsEPFRSoS_E
	leaq	-28(%rbp), %rax
	movl	$3, %edx
	movq	%rax, %rcx
	call	_Z6MinMaxIiESt4pairIT_S1_EPKS1_y
	movq	%rax, -48(%rbp)
	movl	-48(%rbp), %eax
	movl	%eax, %edx
	movq	.refptr._ZSt4cout(%rip), %rax
	movq	%rax, %rcx
	call	_ZNSolsEi
	movq	%rax, %rcx
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movq	%rax, %rcx
	movl	-44(%rbp), %eax
	movl	%eax, %edx
	call	_ZNSolsEi
	movq	%rax, %rcx
	movq	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_(%rip), %rax
	movq	%rax, %rdx
	call	_ZNSolsEPFRSoS_E
	leaq	-40(%rbp), %rax
	movl	$3, %edx
	movq	%rax, %rcx
	call	_Z6MinMaxIfESt4pairIT_S1_EPKS1_y
	movq	%rax, -56(%rbp)
	movss	-56(%rbp), %xmm0
	movaps	%xmm0, %xmm1
	movq	.refptr._ZSt4cout(%rip), %rax
	movq	%rax, %rcx
	call	_ZNSolsEf
	movq	%rax, %rcx
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movss	-52(%rbp), %xmm0
	movaps	%xmm0, %xmm1
	movq	%rax, %rcx
	call	_ZNSolsEf
	movq	%rax, %rcx
	movq	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_(%rip), %rax
	movq	%rax, %rdx
	call	_ZNSolsEPFRSoS_E
	movl	$0, %eax
	addq	$96, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_Z3AddIiET_S0_S0_,"x"
	.linkonce discard
	.globl	_Z3AddIiET_S0_S0_
	.def	_Z3AddIiET_S0_S0_;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z3AddIiET_S0_S0_
_Z3AddIiET_S0_S0_:
.LFB2821:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movl	16(%rbp), %edx
	movl	24(%rbp), %eax
	addl	%edx, %eax
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_Z3AddIdET_S0_S0_,"x"
	.linkonce discard
	.globl	_Z3AddIdET_S0_S0_
	.def	_Z3AddIdET_S0_S0_;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z3AddIdET_S0_S0_
_Z3AddIdET_S0_S0_:
.LFB2822:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movsd	%xmm0, 16(%rbp)
	movsd	%xmm1, 24(%rbp)
	movsd	16(%rbp), %xmm0
	addsd	24(%rbp), %xmm0
	movq	%xmm0, %rax
	movq	%rax, %xmm0
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_Z8ArraySumIiET_PKS0_y,"x"
	.linkonce discard
	.globl	_Z8ArraySumIiET_PKS0_y
	.def	_Z8ArraySumIiET_PKS0_y;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z8ArraySumIiET_PKS0_y
_Z8ArraySumIiET_PKS0_y:
.LFB2827:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movl	$0, -4(%rbp)
	movl	$0, -8(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L8
.L9:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, -8(%rbp)
	addl	$1, -4(%rbp)
.L8:
	movl	-4(%rbp), %eax
	cltq
	cmpq	24(%rbp), %rax
	jb	.L9
	movl	-8(%rbp), %eax
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_Z8ArraySumIfET_PKS0_y,"x"
	.linkonce discard
	.globl	_Z8ArraySumIfET_PKS0_y
	.def	_Z8ArraySumIfET_PKS0_y;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z8ArraySumIfET_PKS0_y
_Z8ArraySumIfET_PKS0_y:
.LFB2828:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movl	$0, -4(%rbp)
	pxor	%xmm0, %xmm0
	movss	%xmm0, -8(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L12
.L13:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movss	(%rax), %xmm0
	movss	%xmm0, -8(%rbp)
	addl	$1, -4(%rbp)
.L12:
	movl	-4(%rbp), %eax
	cltq
	cmpq	24(%rbp), %rax
	jb	.L13
	movss	-8(%rbp), %xmm0
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_Z3MaxIiET_PKS0_y,"x"
	.linkonce discard
	.globl	_Z3MaxIiET_PKS0_y
	.def	_Z3MaxIiET_PKS0_y;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z3MaxIiET_PKS0_y
_Z3MaxIiET_PKS0_y:
.LFB2829:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movl	$0, -4(%rbp)
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, -8(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L16
.L18:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	cmpl	%eax, -8(%rbp)
	jge	.L17
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, -8(%rbp)
.L17:
	addl	$1, -4(%rbp)
.L16:
	movl	-4(%rbp), %eax
	cltq
	cmpq	24(%rbp), %rax
	jb	.L18
	movl	-8(%rbp), %eax
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_Z3MaxIfET_PKS0_y,"x"
	.linkonce discard
	.globl	_Z3MaxIfET_PKS0_y
	.def	_Z3MaxIfET_PKS0_y;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z3MaxIfET_PKS0_y
_Z3MaxIfET_PKS0_y:
.LFB2830:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movl	$0, -4(%rbp)
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movss	(%rax), %xmm0
	movss	%xmm0, -8(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L21
.L24:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movss	(%rax), %xmm0
	comiss	-8(%rbp), %xmm0
	jbe	.L22
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movss	(%rax), %xmm0
	movss	%xmm0, -8(%rbp)
.L22:
	addl	$1, -4(%rbp)
.L21:
	movl	-4(%rbp), %eax
	cltq
	cmpq	24(%rbp), %rax
	jb	.L24
	movss	-8(%rbp), %xmm0
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_Z6MinMaxIiESt4pairIT_S1_EPKS1_y,"x"
	.linkonce discard
	.globl	_Z6MinMaxIiESt4pairIT_S1_EPKS1_y
	.def	_Z6MinMaxIiESt4pairIT_S1_EPKS1_y;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z6MinMaxIiESt4pairIT_S1_EPKS1_y
_Z6MinMaxIiESt4pairIT_S1_EPKS1_y:
.LFB2831:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$64, %rsp
	.seh_stackalloc	64
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movq	$0, -20(%rbp)
	movl	$0, -4(%rbp)
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, -24(%rbp)
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, -28(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L28
.L31:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %edx
	movl	-24(%rbp), %eax
	cmpl	%eax, %edx
	jle	.L29
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, -24(%rbp)
.L29:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %edx
	movl	-28(%rbp), %eax
	cmpl	%eax, %edx
	jge	.L30
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, -28(%rbp)
.L30:
	addl	$1, -4(%rbp)
.L28:
	movl	-4(%rbp), %eax
	cltq
	cmpq	24(%rbp), %rax
	jb	.L31
	leaq	-24(%rbp), %rcx
	leaq	-28(%rbp), %rdx
	leaq	-12(%rbp), %rax
	movq	%rcx, %r8
	movq	%rax, %rcx
	call	_ZNSt4pairIiiEC1IRiS2_Lb1EEEOT_OT0_
	leaq	-12(%rbp), %rdx
	leaq	-20(%rbp), %rax
	movq	%rax, %rcx
	call	_ZNSt4pairIiiEaSEOS0_
	movq	-20(%rbp), %rax
	addq	$64, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_Z6MinMaxIfESt4pairIT_S1_EPKS1_y,"x"
	.linkonce discard
	.globl	_Z6MinMaxIfESt4pairIT_S1_EPKS1_y
	.def	_Z6MinMaxIfESt4pairIT_S1_EPKS1_y;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z6MinMaxIfESt4pairIT_S1_EPKS1_y
_Z6MinMaxIfESt4pairIT_S1_EPKS1_y:
.LFB2839:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$64, %rsp
	.seh_stackalloc	64
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movq	$0, -20(%rbp)
	movl	$0, -4(%rbp)
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movss	(%rax), %xmm0
	movss	%xmm0, -24(%rbp)
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movss	(%rax), %xmm0
	movss	%xmm0, -28(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L34
.L39:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movss	(%rax), %xmm0
	movss	-24(%rbp), %xmm1
	comiss	%xmm1, %xmm0
	jbe	.L35
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movss	(%rax), %xmm0
	movss	%xmm0, -24(%rbp)
.L35:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movss	(%rax), %xmm1
	movss	-28(%rbp), %xmm0
	comiss	%xmm1, %xmm0
	jbe	.L37
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movss	(%rax), %xmm0
	movss	%xmm0, -28(%rbp)
.L37:
	addl	$1, -4(%rbp)
.L34:
	movl	-4(%rbp), %eax
	cltq
	cmpq	24(%rbp), %rax
	jb	.L39
	leaq	-24(%rbp), %rcx
	leaq	-28(%rbp), %rdx
	leaq	-12(%rbp), %rax
	movq	%rcx, %r8
	movq	%rax, %rcx
	call	_ZNSt4pairIffEC1IRfS2_Lb1EEEOT_OT0_
	leaq	-12(%rbp), %rdx
	leaq	-20(%rbp), %rax
	movq	%rax, %rcx
	call	_ZNSt4pairIffEaSEOS0_
	movq	-20(%rbp), %rax
	addq	$64, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZNSt4pairIiiEC1IRiS2_Lb1EEEOT_OT0_,"x"
	.linkonce discard
	.align 2
	.globl	_ZNSt4pairIiiEC1IRiS2_Lb1EEEOT_OT0_
	.def	_ZNSt4pairIiiEC1IRiS2_Lb1EEEOT_OT0_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt4pairIiiEC1IRiS2_Lb1EEEOT_OT0_
_ZNSt4pairIiiEC1IRiS2_Lb1EEEOT_OT0_:
.LFB2953:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movq	%r8, 32(%rbp)
	movq	24(%rbp), %rax
	movq	%rax, %rcx
	call	_ZSt7forwardIRiEOT_RNSt16remove_referenceIS1_E4typeE
	movl	(%rax), %edx
	movq	16(%rbp), %rax
	movl	%edx, (%rax)
	movq	32(%rbp), %rax
	movq	%rax, %rcx
	call	_ZSt7forwardIRiEOT_RNSt16remove_referenceIS1_E4typeE
	movl	(%rax), %edx
	movq	16(%rbp), %rax
	movl	%edx, 4(%rax)
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZNSt4pairIiiEaSEOS0_,"x"
	.linkonce discard
	.align 2
	.globl	_ZNSt4pairIiiEaSEOS0_
	.def	_ZNSt4pairIiiEaSEOS0_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt4pairIiiEaSEOS0_
_ZNSt4pairIiiEaSEOS0_:
.LFB2954:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movq	24(%rbp), %rax
	movq	%rax, %rcx
	call	_ZSt7forwardIiEOT_RNSt16remove_referenceIS0_E4typeE
	movl	(%rax), %edx
	movq	16(%rbp), %rax
	movl	%edx, (%rax)
	movq	24(%rbp), %rax
	addq	$4, %rax
	movq	%rax, %rcx
	call	_ZSt7forwardIiEOT_RNSt16remove_referenceIS0_E4typeE
	movl	(%rax), %edx
	movq	16(%rbp), %rax
	movl	%edx, 4(%rax)
	movq	16(%rbp), %rax
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZNSt4pairIffEC1IRfS2_Lb1EEEOT_OT0_,"x"
	.linkonce discard
	.align 2
	.globl	_ZNSt4pairIffEC1IRfS2_Lb1EEEOT_OT0_
	.def	_ZNSt4pairIffEC1IRfS2_Lb1EEEOT_OT0_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt4pairIffEC1IRfS2_Lb1EEEOT_OT0_
_ZNSt4pairIffEC1IRfS2_Lb1EEEOT_OT0_:
.LFB2957:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movq	%r8, 32(%rbp)
	movq	24(%rbp), %rax
	movq	%rax, %rcx
	call	_ZSt7forwardIRfEOT_RNSt16remove_referenceIS1_E4typeE
	movss	(%rax), %xmm0
	movq	16(%rbp), %rax
	movss	%xmm0, (%rax)
	movq	32(%rbp), %rax
	movq	%rax, %rcx
	call	_ZSt7forwardIRfEOT_RNSt16remove_referenceIS1_E4typeE
	movss	(%rax), %xmm0
	movq	16(%rbp), %rax
	movss	%xmm0, 4(%rax)
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZNSt4pairIffEaSEOS0_,"x"
	.linkonce discard
	.align 2
	.globl	_ZNSt4pairIffEaSEOS0_
	.def	_ZNSt4pairIffEaSEOS0_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt4pairIffEaSEOS0_
_ZNSt4pairIffEaSEOS0_:
.LFB2958:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movq	24(%rbp), %rax
	movq	%rax, %rcx
	call	_ZSt7forwardIfEOT_RNSt16remove_referenceIS0_E4typeE
	movss	(%rax), %xmm0
	movq	16(%rbp), %rax
	movss	%xmm0, (%rax)
	movq	24(%rbp), %rax
	addq	$4, %rax
	movq	%rax, %rcx
	call	_ZSt7forwardIfEOT_RNSt16remove_referenceIS0_E4typeE
	movss	(%rax), %xmm0
	movq	16(%rbp), %rax
	movss	%xmm0, 4(%rax)
	movq	16(%rbp), %rax
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZSt7forwardIRiEOT_RNSt16remove_referenceIS1_E4typeE,"x"
	.linkonce discard
	.globl	_ZSt7forwardIRiEOT_RNSt16remove_referenceIS1_E4typeE
	.def	_ZSt7forwardIRiEOT_RNSt16remove_referenceIS1_E4typeE;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt7forwardIRiEOT_RNSt16remove_referenceIS1_E4typeE
_ZSt7forwardIRiEOT_RNSt16remove_referenceIS1_E4typeE:
.LFB3033:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rax
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZSt7forwardIiEOT_RNSt16remove_referenceIS0_E4typeE,"x"
	.linkonce discard
	.globl	_ZSt7forwardIiEOT_RNSt16remove_referenceIS0_E4typeE
	.def	_ZSt7forwardIiEOT_RNSt16remove_referenceIS0_E4typeE;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt7forwardIiEOT_RNSt16remove_referenceIS0_E4typeE
_ZSt7forwardIiEOT_RNSt16remove_referenceIS0_E4typeE:
.LFB3034:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rax
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZSt7forwardIRfEOT_RNSt16remove_referenceIS1_E4typeE,"x"
	.linkonce discard
	.globl	_ZSt7forwardIRfEOT_RNSt16remove_referenceIS1_E4typeE
	.def	_ZSt7forwardIRfEOT_RNSt16remove_referenceIS1_E4typeE;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt7forwardIRfEOT_RNSt16remove_referenceIS1_E4typeE
_ZSt7forwardIRfEOT_RNSt16remove_referenceIS1_E4typeE:
.LFB3035:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rax
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZSt7forwardIfEOT_RNSt16remove_referenceIS0_E4typeE,"x"
	.linkonce discard
	.globl	_ZSt7forwardIfEOT_RNSt16remove_referenceIS0_E4typeE
	.def	_ZSt7forwardIfEOT_RNSt16remove_referenceIS0_E4typeE;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt7forwardIfEOT_RNSt16remove_referenceIS0_E4typeE
_ZSt7forwardIfEOT_RNSt16remove_referenceIS0_E4typeE:
.LFB3036:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rax
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
_ZNSt8__detail30__integer_to_chars_is_unsignedIjEE:
	.byte	1
_ZNSt8__detail30__integer_to_chars_is_unsignedImEE:
	.byte	1
_ZNSt8__detail30__integer_to_chars_is_unsignedIyEE:
	.byte	1
	.align 8
.LC0:
	.long	-1717986918
	.long	1074370969
	.align 8
.LC1:
	.long	-1717986918
	.long	1073846681
	.align 4
.LC4:
	.long	1067030938
	.align 4
.LC5:
	.long	1081711002
	.align 4
.LC6:
	.long	1091777331
	.ident	"GCC: (MinGW-W64 x86_64-ucrt-mcf-seh, built by Brecht Sanders) 13.2.0"
	.def	_ZNSolsEi;	.scl	2;	.type	32;	.endef
	.def	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc;	.scl	2;	.type	32;	.endef
	.def	_ZNSolsEf;	.scl	2;	.type	32;	.endef
	.def	_ZNSolsEPFRSoS_E;	.scl	2;	.type	32;	.endef
	.section	.rdata$.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, "dr"
	.globl	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	.linkonce	discard
.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_:
	.quad	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	.section	.rdata$.refptr._ZSt4cout, "dr"
	.globl	.refptr._ZSt4cout
	.linkonce	discard
.refptr._ZSt4cout:
	.quad	_ZSt4cout
