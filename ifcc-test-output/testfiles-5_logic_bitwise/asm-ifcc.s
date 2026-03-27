.globl main
main:
    pushq %rbp
    movq %rsp, %rbp
    subq $96, %rsp
.L_main_0:
    movl $12, %eax
    movl %eax, -20(%rbp)
    movl -20(%rbp), %eax
    movl %eax, -4(%rbp)
    movl $7, %eax
    movl %eax, -24(%rbp)
    movl -24(%rbp), %eax
    movl %eax, -8(%rbp)
    movl -4(%rbp), %eax
    andl -8(%rbp), %eax
    movl %eax, -28(%rbp)
    movl $2, %eax
    movl %eax, -32(%rbp)
    movl -32(%rbp), %ecx
    movl -28(%rbp), %eax
    sall %cl, %eax
    movl %eax, -36(%rbp)
    movl -4(%rbp), %eax
    xorl -8(%rbp), %eax
    movl %eax, -40(%rbp)
    movl $1, %eax
    movl %eax, -44(%rbp)
    movl -44(%rbp), %ecx
    movl -40(%rbp), %eax
    sarl %cl, %eax
    movl %eax, -48(%rbp)
    movl -36(%rbp), %eax
    orl -48(%rbp), %eax
    movl %eax, -52(%rbp)
    movl $15, %eax
    movl %eax, -56(%rbp)
    movl -56(%rbp), %ecx
    movl -52(%rbp), %eax
    cmpl %ecx, %eax
    setg %al
    movzbl %al, %eax
    movl %eax, -60(%rbp)
    movl -60(%rbp), %eax
    movl %eax, -12(%rbp)
    movl $0, %eax
    movl %eax, -64(%rbp)
    movl -64(%rbp), %ecx
    movl -12(%rbp), %eax
    cmpl %ecx, %eax
    setne %al
    movzbl %al, %eax
    movl %eax, -68(%rbp)
    movl $3, %eax
    movl %eax, -72(%rbp)
    movl -72(%rbp), %ecx
    movl -4(%rbp), %eax
    sarl %cl, %eax
    movl %eax, -76(%rbp)
    movl -68(%rbp), %eax
    andl -76(%rbp), %eax
    movl %eax, -80(%rbp)
    movl -80(%rbp), %eax
    movl %eax, -12(%rbp)
    movl -12(%rbp), %eax
    jmp .L_end_main
    movl $0, %eax
    movl %eax, -84(%rbp)
    movl -84(%rbp), %eax
    jmp .L_end_main
.L_end_main:
    movq %rbp, %rsp
    popq %rbp
    ret
