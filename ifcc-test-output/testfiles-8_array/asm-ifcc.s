.globl main
main:
    pushq %rbp
    movq %rsp, %rbp
    subq $80, %rsp
.L_main_0:
    movl $10, %eax
    movl %eax, -52(%rbp)
    movl $0, %eax
    movl %eax, -56(%rbp)
    movl -56(%rbp), %eax
    movl %eax, -44(%rbp)
    movl $100, %eax
    movl %eax, -60(%rbp)
    movl -44(%rbp), %eax
    cltq
    movl -60(%rbp), %ecx
    movl %ecx, -40(%rbp, %rax, 4)
    movl $0, %eax
    movl %eax, -64(%rbp)
    movl -64(%rbp), %eax
    cltq
    movl -40(%rbp, %rax, 4), %ecx
    movl %ecx, -68(%rbp)
    movl -68(%rbp), %eax
    jmp .L_end_main
    movl $0, %eax
    movl %eax, -72(%rbp)
    movl -72(%rbp), %eax
    jmp .L_end_main
.L_end_main:
    movq %rbp, %rsp
    popq %rbp
    ret
