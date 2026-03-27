.globl main
main:
    pushq %rbp
    movq %rsp, %rbp
    subq $48, %rsp
.L_main_entry:
    movl $10, %eax
    movl %eax, -20(%rbp)
    movl -20(%rbp), %eax
    movl %eax, -4(%rbp)
    movl $5, %eax
    movl %eax, -24(%rbp)
    movl -24(%rbp), %eax
    movl %eax, -8(%rbp)
    movl $2, %eax
    movl %eax, -28(%rbp)
    movl -28(%rbp), %eax
    movl %eax, -12(%rbp)
    movl -4(%rbp), %eax
    addl -8(%rbp), %eax
    movl %eax, -32(%rbp)
    movl -32(%rbp), %eax
    imull -12(%rbp), %eax
    movl %eax, -36(%rbp)
    movl -8(%rbp), %ecx
    movl -4(%rbp), %eax
    cltd
    idivl %ecx
    movl %eax, -40(%rbp)
    movl -36(%rbp), %eax
    subl -40(%rbp), %eax
    movl %eax, -44(%rbp)
    movl -44(%rbp), %eax
    movl %eax, -16(%rbp)
    movl -16(%rbp), %eax
    jmp end_main
end_main:
    movq %rbp, %rsp
    popq %rbp
    ret
