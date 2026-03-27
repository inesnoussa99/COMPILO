	.file	"input.c"
	.text
	.globl	safety_check
	.type	safety_check, @function
safety_check:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	cmpl	$0, -8(%rbp)
	je	.L2
	movl	-4(%rbp), %eax
	cltd
	idivl	-8(%rbp)
	testl	%eax, %eax
	jle	.L2
	movl	$1, %eax
	jmp	.L4
.L2:
	movl	$0, %eax
.L4:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	safety_check, .-safety_check
	.globl	weight_sum
	.type	weight_sum, @function
weight_sum:
.LFB1:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -20(%rbp)
	movl	%esi, -24(%rbp)
	movl	-20(%rbp), %eax
	cmpl	-24(%rbp), %eax
	setg	%al
	movzbl	%al, %eax
	imull	-20(%rbp), %eax
	movl	%eax, %edx
	movl	-20(%rbp), %eax
	cmpl	-24(%rbp), %eax
	setle	%al
	movzbl	%al, %eax
	imull	-24(%rbp), %eax
	addl	%edx, %eax
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	weight_sum, .-weight_sum
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$0, -44(%rbp)
	movl	$42, -40(%rbp)
	movl	$1, -36(%rbp)
	movl	$10, -32(%rbp)
	movl	$100, -28(%rbp)
	movl	-28(%rbp), %eax
	movl	%eax, -44(%rbp)
	movl	-32(%rbp), %eax
	addl	%eax, -44(%rbp)
	movl	-36(%rbp), %eax
	addl	%eax, -44(%rbp)
	movl	$0, -24(%rbp)
	movl	-44(%rbp), %edx
	movl	-40(%rbp), %eax
	movl	%edx, %esi
	movl	%eax, %edi
	call	weight_sum
	testl	%eax, %eax
	jg	.L8
	movl	-24(%rbp), %eax
	addl	$1, %eax
	cmpl	$2, %eax
	setbe	%al
	movl	$0, %edx
	testb	%al, %al
	movl	%edx, %eax
	cmovne	-24(%rbp), %eax
	testl	%eax, %eax
	jne	.L9
.L8:
	movl	$0, %esi
	movl	$10, %edi
	call	safety_check
	movl	%eax, -20(%rbp)
	movl	-20(%rbp), %eax
	cltq
	movl	-44(%rbp), %edx
	movl	%edx, -16(%rbp,%rax,4)
	movl	-16(%rbp), %eax
	subl	$11, %eax
	jmp	.L10
.L9:
	movl	$-1, %eax
.L10:
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L11
	call	__stack_chk_fail@PLT
.L11:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 13.3.0-6ubuntu2~24.04.1) 13.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
