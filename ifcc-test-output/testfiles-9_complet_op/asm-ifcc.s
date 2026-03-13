.globl main
main:
    pushq %rbp
    movq %rsp, %rbp
    subq $1104, %rsp
    movl $10, %eax
    movl $2, %eax
    movl $15, %eax
    movl %eax, -4(%rbp)
    movl $4, %eax
    movl %eax, -8(%rbp)
    movl $2, %eax
    movl %eax, -12(%rbp)
    movl -4(%rbp), %eax
    movq %rax, -88(%rbp)
    movl -8(%rbp), %eax
    movl %eax, %ecx
    movq -88(%rbp), %rax
    imull %ecx, %eax
    movq %rax, -88(%rbp)
    movl -12(%rbp), %eax
    movq %rax, -96(%rbp)
    movl $3, %eax
    movl %eax, %ecx
    movq -96(%rbp), %rax
    sall %cl, %eax
    movq -88(%rbp), %rdx
    addl %edx, %eax
    movq %rax, -88(%rbp)
    movl -4(%rbp), %eax
    movq %rax, -96(%rbp)
    movl -12(%rbp), %eax
    movl %eax, %ecx
    movq -96(%rbp), %rax
    cltd
    idivl %ecx
    notl %eax
    movq %rax, -96(%rbp)
    movl $255, %eax
    movl %eax, %ecx
    movq -96(%rbp), %rax
    andl %ecx, %eax
    movl %eax, %ecx
    movq -88(%rbp), %rax
    xorl %ecx, %eax
    movq %rax, -88(%rbp)
    movl $100, %eax
    movq %rax, -96(%rbp)
    movl $1, %eax
    movl %eax, %ecx
    movq -96(%rbp), %rax
    sar %cl, %eax
    movl %eax, %ecx
    movq -88(%rbp), %rax
    orl %ecx, %eax
    movl %eax, -16(%rbp)
    movl $0, %eax
    cltq
    movq %rax, -88(%rbp)
    movl $1, %eax
    movl %eax, %ecx
    movq -88(%rbp), %rax
    movl %ecx, -56(%rbp, %rax, 4)
    movl $1, %eax
    cltq
    movq %rax, -88(%rbp)
    movl $5, %eax
    movl %eax, %ecx
    movq -88(%rbp), %rax
    movl %ecx, -56(%rbp, %rax, 4)
    movl $2, %eax
    cltq
    movq %rax, -88(%rbp)
    movl $8, %eax
    movl %eax, %ecx
    movq -88(%rbp), %rax
    movl %ecx, -56(%rbp, %rax, 4)
    movl $0, %eax
    cltq
    movl -56(%rbp, %rax, 4), %eax
    cltq
    movq %rax, -88(%rbp)
    movl -4(%rbp), %eax
    movq %rax, -96(%rbp)
    movl -8(%rbp), %eax
    movq -96(%rbp), %rdx
    addl %edx, %eax
    movl %eax, %ecx
    movq -88(%rbp), %rax
    movl %ecx, -56(%rbp, %rax, 4)
    movl $1, %eax
    cltq
    movl -56(%rbp, %rax, 4), %eax
    movq %rax, -88(%rbp)
    movl $17, %eax
    movq -88(%rbp), %rdx
    negl %eax
    addl %edx, %eax
    cltq
    movq %rax, -88(%rbp)
    movl $2, %eax
    cltq
    movl -56(%rbp, %rax, 4), %eax
    movq %rax, -96(%rbp)
    movl -12(%rbp), %eax
    movl %eax, %ecx
    movq -96(%rbp), %rax
    imull %ecx, %eax
    movl %eax, %ecx
    movq -88(%rbp), %rax
    movl %ecx, -56(%rbp, %rax, 4)
    movl $100, %eax
    movl %eax, -68(%rbp)
    movl -68(%rbp), %eax
    movq %rax, -88(%rbp)
    movl $2, %eax
    movl %eax, %ecx
    movq -88(%rbp), %rax
    cltd
    idivl %ecx
    movl %eax, -72(%rbp)
    movl -16(%rbp), %eax
    movq %rax, -88(%rbp)
    movl -72(%rbp), %eax
    movq -88(%rbp), %rdx
    addl %edx, %eax
    movl %eax, -16(%rbp)
    movl $1000, %eax
    movl %eax, -76(%rbp)
    movl -16(%rbp), %eax
    movq %rax, -88(%rbp)
    movl -76(%rbp), %eax
    movq -88(%rbp), %rdx
    negl %eax
    addl %edx, %eax
    movq %rax, -88(%rbp)
    movl -68(%rbp), %eax
    movq -88(%rbp), %rdx
    addl %edx, %eax
    movl %eax, -16(%rbp)
    movl -4(%rbp), %eax
    movq %rax, -88(%rbp)
    movl -8(%rbp), %eax
    movl %eax, %ecx
    movq -88(%rbp), %rax
    cmpl %ecx, %eax
    setg %al
    movzbl %al, %eax
    testl %eax, %eax
    je logical_and_false_1
    movl -12(%rbp), %eax
    movq %rax, -88(%rbp)
    movl $2, %eax
    movl %eax, %ecx
    movq -88(%rbp), %rax
    cmpl %ecx, %eax
    sete %al
    movzbl %al, %eax
    testl %eax, %eax
    jne logical_or_true_2
    movl -16(%rbp), %eax
    movq %rax, -88(%rbp)
    movl $0, %eax
    movl %eax, %ecx
    movq -88(%rbp), %rax
    cmpl %ecx, %eax
    setl %al
    movzbl %al, %eax
    testl %eax, %eax
    jne logical_or_true_2
    movl $0, %eax
    jmp logical_or_end_2
logical_or_true_2:
    movl $1, %eax
logical_or_end_2:
    testl %eax, %eax
    je logical_and_false_1
    movl $1, %eax
    jmp logical_and_end_1
logical_and_false_1:
    movl $0, %eax
logical_and_end_1:
    cmpl $0, %eax
    je else_0
    movl -16(%rbp), %eax
    movq %rax, -88(%rbp)
    movl $0, %eax
    movl %eax, %ecx
    movq -88(%rbp), %rax
    cmpl %ecx, %eax
    sete %al
    movzbl %al, %eax
    cmpl $0, %eax
    sete %al
    movzbl %al, %eax
    cmpl $0, %eax
    je else_3
    movl $0, %eax
    cltq
    movq %rax, -88(%rbp)
    movl $42, %eax
    movl %eax, %ecx
    movq -88(%rbp), %rax
    movl %ecx, -64(%rbp, %rax, 4)
    jmp end_if_3
else_3:
    movl $0, %eax
    cltq
    movq %rax, -88(%rbp)
    movl $0, %eax
    movl %eax, %ecx
    movq -88(%rbp), %rax
    movl %ecx, -64(%rbp, %rax, 4)
end_if_3:
    jmp end_if_0
else_0:
    movl $0, %eax
    cltq
    movq %rax, -88(%rbp)
    movl $1, %eax
    movl %eax, %ecx
    movq -88(%rbp), %rax
    movl %ecx, -64(%rbp, %rax, 4)
end_if_0:
    movl $1, %eax
    cltq
    movq %rax, -88(%rbp)
    movl -4(%rbp), %eax
    movq %rax, -96(%rbp)
    movl -8(%rbp), %eax
    movl %eax, %ecx
    movq -96(%rbp), %rax
    cmpl %ecx, %eax
    setne %al
    movzbl %al, %eax
    movq %rax, -96(%rbp)
    movl -12(%rbp), %eax
    movq %rax, -104(%rbp)
    movl $10, %eax
    movl %eax, %ecx
    movq -104(%rbp), %rax
    cmpl %ecx, %eax
    setle %al
    movzbl %al, %eax
    movq %rax, -104(%rbp)
    movl -16(%rbp), %eax
    movq %rax, -112(%rbp)
    movl $100, %eax
    movl %eax, %ecx
    movq -112(%rbp), %rax
    cmpl %ecx, %eax
    setg %al
    movzbl %al, %eax
    movl %eax, %ecx
    movq -104(%rbp), %rax
    andl %ecx, %eax
    movl %eax, %ecx
    movq -96(%rbp), %rax
    xorl %ecx, %eax
    movl %eax, %ecx
    movq -88(%rbp), %rax
    movl %ecx, -64(%rbp, %rax, 4)
    movl $0, %eax
    cltq
    movl -64(%rbp, %rax, 4), %eax
    movq %rax, -88(%rbp)
    movl $1, %eax
    cltq
    movl -64(%rbp, %rax, 4), %eax
    movq -88(%rbp), %rdx
    addl %edx, %eax
    movq %rax, -88(%rbp)
    movl $2, %eax
    cltq
    movl -56(%rbp, %rax, 4), %eax
    movq -88(%rbp), %rdx
    addl %edx, %eax
    movq %rax, -88(%rbp)
    movl -4(%rbp), %eax
    movq %rax, -96(%rbp)
    movl $14, %eax
    movq -96(%rbp), %rdx
    negl %eax
    addl %edx, %eax
    movl %eax, %ecx
    movq -88(%rbp), %rax
    imull %ecx, %eax
    jmp end_main
end_main:
    movq %rbp, %rsp
    popq %rbp
    ret
