.globl main
main:
    pushq %rbp
    movq %rsp, %rbp
    subq $80, %rsp
.L_main_entry:
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
    je .L2
    jmp .L0
.L0:
    movl $100, %eax
    movl %eax, -44(%rbp)
    movl -44(%rbp), %eax
    movl %eax, -16(%rbp)
    jmp .L1
.L2:
    movl $200, %eax
    movl %eax, -48(%rbp)
    movl -48(%rbp), %eax
    movl %eax, -16(%rbp)
    jmp .L1
.L1:
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
    je .L5
    jmp .L3
.L3:
    movl -4(%rbp), %ecx
    movl -12(%rbp), %eax
    cmpl %ecx, %eax
    setl %al
    movzbl %al, %eax
    movl %eax, -60(%rbp)
    movl -60(%rbp), %eax
    cmpl $0, %eax
    je .L8
    jmp .L6
.L6:
    movl $1, %eax
    movl %eax, -64(%rbp)
    movl -64(%rbp), %eax
    movl %eax, -16(%rbp)
    jmp .L7
.L8:
    movl $50, %eax
    movl %eax, -68(%rbp)
    movl -68(%rbp), %eax
    movl %eax, -20(%rbp)
    movl -20(%rbp), %eax
    movl %eax, -16(%rbp)
    jmp .L7
.L7:
    jmp .L4
.L5:
    movl $0, %eax
    movl %eax, -72(%rbp)
    movl -72(%rbp), %eax
    movl %eax, -16(%rbp)
    jmp .L4
.L4:
    movl -16(%rbp), %eax
    jmp end_main
end_main:
    movq %rbp, %rsp
    popq %rbp
    ret
