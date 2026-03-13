	.file	"input.c"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$96, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$15, -84(%rbp)
	movl	$4, -80(%rbp)
	movl	$2, -76(%rbp)
	movl	-84(%rbp), %eax
	imull	-80(%rbp), %eax
	movl	-76(%rbp), %edx
	sall	$3, %edx
	leal	(%rax,%rdx), %ecx
	movl	-84(%rbp), %eax
	cltd
	idivl	-76(%rbp)
	notl	%eax
	movzbl	%al, %eax
	xorl	%ecx, %eax
	orl	$50, %eax
	movl	%eax, -72(%rbp)
	movl	$1, -48(%rbp)
	movl	$5, -44(%rbp)
	movl	$8, -40(%rbp)
	movl	-48(%rbp), %eax
	movl	-84(%rbp), %ecx
	movl	-80(%rbp), %edx
	addl	%ecx, %edx
	cltq
	movl	%edx, -48(%rbp,%rax,4)
	movl	-40(%rbp), %eax
	movl	-44(%rbp), %edx
	leal	-17(%rdx), %ecx
	imull	-76(%rbp), %eax
	movl	%eax, %edx
	movslq	%ecx, %rax
	movl	%edx, -48(%rbp,%rax,4)
	movl	$100, -68(%rbp)
	movl	-68(%rbp), %eax
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%edx, %eax
	sarl	%eax
	movl	%eax, -64(%rbp)
	movl	-64(%rbp), %eax
	addl	%eax, -72(%rbp)
	movl	$1000, -60(%rbp)
	movl	-72(%rbp), %eax
	subl	-60(%rbp), %eax
	movl	%eax, %edx
	movl	-68(%rbp), %eax
	addl	%edx, %eax
	movl	%eax, -72(%rbp)
	movl	-84(%rbp), %eax
	cmpl	-80(%rbp), %eax
	jle	.L2
	cmpl	$2, -76(%rbp)
	je	.L3
	cmpl	$0, -72(%rbp)
	jns	.L2
.L3:
	cmpl	$0, -72(%rbp)
	je	.L4
	movl	$42, -56(%rbp)
	jmp	.L6
.L4:
	movl	$0, -56(%rbp)
	jmp	.L6
.L2:
	movl	$1, -56(%rbp)
.L6:
	movl	-84(%rbp), %eax
	cmpl	-80(%rbp), %eax
	setne	%al
	movzbl	%al, %edx
	cmpl	$10, -76(%rbp)
	setle	%cl
	cmpl	$100, -72(%rbp)
	setg	%al
	andl	%ecx, %eax
	movzbl	%al, %eax
	xorl	%edx, %eax
	movl	%eax, -52(%rbp)
	movl	-56(%rbp), %edx
	movl	-52(%rbp), %eax
	addl	%eax, %edx
	movl	-40(%rbp), %eax
	addl	%eax, %edx
	movl	-84(%rbp), %eax
	subl	$14, %eax
	imull	%edx, %eax
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L8
	call	__stack_chk_fail@PLT
.L8:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
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
