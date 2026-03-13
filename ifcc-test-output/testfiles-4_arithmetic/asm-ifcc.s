.globl main
main:
    pushq %rbp
    movq %rsp, %rbp
    subq $1040, %rsp
    movl $10, %eax
    movl %eax, -4(%rbp)
    movl $5, %eax
    movl %eax, -8(%rbp)
    movl $2, %eax
    movl %eax, -12(%rbp)
    movl -4(%rbp), %eax
    movq %rax, -24(%rbp)
    movl -8(%rbp), %eax
    movq -24(%rbp), %rdx
    addl %edx, %eax
    movq %rax, -24(%rbp)
    movl -12(%rbp), %eax
    movl %eax, %ecx
    movq -24(%rbp), %rax
    imull %ecx, %eax
    movq %rax, -24(%rbp)
    movl -4(%rbp), %eax
    movq %rax, -32(%rbp)
    movl -8(%rbp), %eax
    movl %eax, %ecx
    movq -32(%rbp), %rax
    cltd
    idivl %ecx
    movq -24(%rbp), %rdx
    negl %eax
    addl %edx, %eax
    movl %eax, -16(%rbp)
    movl -16(%rbp), %eax
    jmp end_main
end_main:
    movq %rbp, %rsp
    popq %rbp
    ret
