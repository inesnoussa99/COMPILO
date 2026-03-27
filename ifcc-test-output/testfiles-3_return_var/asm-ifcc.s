.globl main
main:
    pushq %rbp
    movq %rsp, %rbp
    subq $16, %rsp
.L_main_0:
    movl $8, %eax
    movl %eax, -12(%rbp)
    movl -12(%rbp), %eax
    movl %eax, -4(%rbp)
    movl -4(%rbp), %eax
    jmp .L_end_main
    movl $0, %eax
    movl %eax, -16(%rbp)
    movl -16(%rbp), %eax
    jmp .L_end_main
.L_end_main:
    movq %rbp, %rsp
    popq %rbp
    ret
