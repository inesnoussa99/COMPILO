.globl main
main:
    pushq %rbp
    movq %rsp, %rbp
    subq $1040, %rsp
    movl $12, %eax
    movl %eax, -4(%rbp)
    movl $7, %eax
    movl %eax, -8(%rbp)
    movl -4(%rbp), %eax
    movq %rax, -24(%rbp)
    movl -8(%rbp), %eax
    movl %eax, %ecx
    movq -24(%rbp), %rax
    andl %ecx, %eax
    movq %rax, -24(%rbp)
    movl $2, %eax
    movl %eax, %ecx
    movq -24(%rbp), %rax
    sall %cl, %eax
    movq %rax, -24(%rbp)
    movl -4(%rbp), %eax
    movq %rax, -32(%rbp)
    movl -8(%rbp), %eax
    movl %eax, %ecx
    movq -32(%rbp), %rax
    xorl %ecx, %eax
    movq %rax, -32(%rbp)
    movl $1, %eax
    movl %eax, %ecx
    movq -32(%rbp), %rax
    sar %cl, %eax
    movl %eax, %ecx
    movq -24(%rbp), %rax
    orl %ecx, %eax
    movq %rax, -24(%rbp)
    movl $15, %eax
    movl %eax, %ecx
    movq -24(%rbp), %rax
    cmpl %ecx, %eax
    setg %al
    movzbl %al, %eax
    movl %eax, -12(%rbp)
    movl -12(%rbp), %eax
    movq %rax, -24(%rbp)
    movl $0, %eax
    movl %eax, %ecx
    movq -24(%rbp), %rax
    cmpl %ecx, %eax
    setne %al
    movzbl %al, %eax
    movq %rax, -24(%rbp)
    movl -4(%rbp), %eax
    movq %rax, -32(%rbp)
    movl $3, %eax
    movl %eax, %ecx
    movq -32(%rbp), %rax
    sar %cl, %eax
    movl %eax, %ecx
    movq -24(%rbp), %rax
    andl %ecx, %eax
    movl %eax, -12(%rbp)
    movl -12(%rbp), %eax
    jmp end_main
end_main:
    movq %rbp, %rsp
    popq %rbp
    ret
