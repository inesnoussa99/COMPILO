.globl main
main:
    pushq %rbp
    movq %rsp, %rbp
    subq $1056, %rsp
    movl $100, %eax
    movl %eax, -4(%rbp)
    movl $2, %eax
    movl %eax, -8(%rbp)
    movl $10, %eax
    movl %eax, -16(%rbp)
    movl -8(%rbp), %eax
    movq %rax, -32(%rbp)
    movl -16(%rbp), %eax
    movl %eax, %ecx
    movq -32(%rbp), %rax
    imull %ecx, %eax
    movl %eax, -8(%rbp)
    movl $5, %eax
    movl %eax, -20(%rbp)
    movl $1, %eax
    movl %eax, -24(%rbp)
    movl -20(%rbp), %eax
    movq %rax, -32(%rbp)
    movl -24(%rbp), %eax
    movq -32(%rbp), %rdx
    addl %edx, %eax
    movq %rax, -32(%rbp)
    movl $10, %eax
    movq -32(%rbp), %rdx
    addl %edx, %eax
    movl %eax, -20(%rbp)
    movl -16(%rbp), %eax
    movq %rax, -32(%rbp)
    movl $5, %eax
    movq -32(%rbp), %rdx
    addl %edx, %eax
    movl %eax, -16(%rbp)
    movl -4(%rbp), %eax
    movq %rax, -32(%rbp)
    movl -8(%rbp), %eax
    movq -32(%rbp), %rdx
    addl %edx, %eax
    movl %eax, -12(%rbp)
    movl -12(%rbp), %eax
    jmp end_main
end_main:
    movq %rbp, %rsp
    popq %rbp
    ret
