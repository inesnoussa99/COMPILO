.globl main
main:
    pushq %rbp
    movq %rsp, %rbp
    subq $1056, %rsp
    movl $10, %eax
    movl %eax, -4(%rbp)
    movl $5, %eax
    movl %eax, -8(%rbp)
    movl $20, %eax
    movl %eax, -12(%rbp)
    movl -4(%rbp), %eax
    movq %rax, -32(%rbp)
    movl -8(%rbp), %eax
    movl %eax, %ecx
    movq -32(%rbp), %rax
    cmpl %ecx, %eax
    setg %al
    movzbl %al, %eax
    cmpl $0, %eax
    je else_0
    movl $100, %eax
    movl %eax, -16(%rbp)
    jmp end_if_0
else_0:
    movl $200, %eax
    movl %eax, -16(%rbp)
end_if_0:
    movl -16(%rbp), %eax
    movq %rax, -32(%rbp)
    movl $100, %eax
    movl %eax, %ecx
    movq -32(%rbp), %rax
    cmpl %ecx, %eax
    sete %al
    movzbl %al, %eax
    cmpl $0, %eax
    je else_1
    movl -12(%rbp), %eax
    movq %rax, -32(%rbp)
    movl -4(%rbp), %eax
    movl %eax, %ecx
    movq -32(%rbp), %rax
    cmpl %ecx, %eax
    setl %al
    movzbl %al, %eax
    cmpl $0, %eax
    je else_2
    movl $1, %eax
    movl %eax, -16(%rbp)
    jmp end_if_2
else_2:
    movl $50, %eax
    movl %eax, -20(%rbp)
    movl -20(%rbp), %eax
    movl %eax, -16(%rbp)
end_if_2:
    jmp end_if_1
else_1:
    movl $0, %eax
    movl %eax, -16(%rbp)
end_if_1:
    movl -16(%rbp), %eax
    jmp end_main
end_main:
    movq %rbp, %rsp
    popq %rbp
    ret
