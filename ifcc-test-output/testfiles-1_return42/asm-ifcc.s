.globl main
main:
    pushq %rbp
    movq %rsp, %rbp
    subq $16, %rsp
.L_main_0:
    movl $42, %eax
    movl %eax, -4(%rbp)
    movl -4(%rbp), %eax
    jmp .L_end_main
    movl $0, %eax
    movl %eax, -8(%rbp)
    movl -8(%rbp), %eax
    jmp .L_end_main
.L_end_main:
    movq %rbp, %rsp
    popq %rbp
    ret
