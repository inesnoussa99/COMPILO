.globl main
main:
    pushq %rbp
    movq %rsp, %rbp
    subq $80, %rsp
.L_main_0:
    movl $10, %eax
    movl %eax, -28(%rbp)
    movl -28(%rbp), %eax
    movl %eax, -4(%rbp)
    movl $5, %eax
    movl %eax, -32(%rbp)
    movl -32(%rbp), %eax
    movl %eax, -8(%rbp)
    movl $20, %eax
    movl %eax, -36(%rbp)
    movl -36(%rbp), %eax
    movl %eax, -12(%rbp)
    movl -8(%rbp), %ecx
    movl -4(%rbp), %eax
    cmpl %ecx, %eax
    setg %al
    movzbl %al, %eax
    movl %eax, -40(%rbp)
    movl -40(%rbp), %eax
    cmpl $0, %eax
    je .L_main_3
    jmp .L_main_1
.L_main_1:
    movl $100, %eax
    movl %eax, -44(%rbp)
    movl -44(%rbp), %eax
    movl %eax, -16(%rbp)
    jmp .L_main_2
.L_main_3:
    movl $200, %eax
    movl %eax, -48(%rbp)
    movl -48(%rbp), %eax
    movl %eax, -16(%rbp)
    jmp .L_main_2
.L_main_2:
    movl $100, %eax
    movl %eax, -52(%rbp)
    movl -52(%rbp), %ecx
    movl -16(%rbp), %eax
    cmpl %ecx, %eax
    sete %al
    movzbl %al, %eax
    movl %eax, -56(%rbp)
    movl -56(%rbp), %eax
    cmpl $0, %eax
    je .L_main_6
    jmp .L_main_4
.L_main_4:
    movl -4(%rbp), %ecx
    movl -12(%rbp), %eax
    cmpl %ecx, %eax
    setl %al
    movzbl %al, %eax
    movl %eax, -60(%rbp)
    movl -60(%rbp), %eax
    cmpl $0, %eax
    je .L_main_9
    jmp .L_main_7
.L_main_7:
    movl $1, %eax
    movl %eax, -64(%rbp)
    movl -64(%rbp), %eax
    movl %eax, -16(%rbp)
    jmp .L_main_8
.L_main_9:
    movl $50, %eax
    movl %eax, -68(%rbp)
    movl -68(%rbp), %eax
    movl %eax, -20(%rbp)
    movl -20(%rbp), %eax
    movl %eax, -16(%rbp)
    jmp .L_main_8
.L_main_8:
    jmp .L_main_5
.L_main_6:
    movl $0, %eax
    movl %eax, -72(%rbp)
    movl -72(%rbp), %eax
    movl %eax, -16(%rbp)
    jmp .L_main_5
.L_main_5:
    movl -16(%rbp), %eax
    jmp .L_end_main
    movl $0, %eax
    movl %eax, -76(%rbp)
    movl -76(%rbp), %eax
    jmp .L_end_main
.L_end_main:
    movq %rbp, %rsp
    popq %rbp
    ret
