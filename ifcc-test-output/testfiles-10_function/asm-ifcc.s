.globl safety_check
safety_check:
    pushq %rbp
    movq %rsp, %rbp
    subq $48, %rsp
.L_safety_check_0:
    movl %edi, %eax
    movl %eax, -4(%rbp)
    movl %esi, %eax
    movl %eax, -8(%rbp)
    movl $0, %eax
    movl %eax, -16(%rbp)
    movl -16(%rbp), %ecx
    movl -8(%rbp), %eax
    cmpl %ecx, %eax
    setne %al
    movzbl %al, %eax
    movl %eax, -20(%rbp)
    movl -20(%rbp), %eax
    cmpl $0, %eax
    je .L_safety_check_3
    jmp .L_safety_check_1
.L_safety_check_1:
    movl -8(%rbp), %ecx
    movl -4(%rbp), %eax
    cltd
    idivl %ecx
    movl %eax, -24(%rbp)
    movl $0, %eax
    movl %eax, -28(%rbp)
    movl -28(%rbp), %ecx
    movl -24(%rbp), %eax
    cmpl %ecx, %eax
    setg %al
    movzbl %al, %eax
    movl %eax, -32(%rbp)
    movl -32(%rbp), %eax
    cmpl $0, %eax
    je .L_safety_check_3
    jmp .L_safety_check_2
.L_safety_check_2:
    movl $1, %eax
    movl %eax, -12(%rbp)
    jmp .L_safety_check_4
.L_safety_check_3:
    movl $0, %eax
    movl %eax, -12(%rbp)
    jmp .L_safety_check_4
.L_safety_check_4:
    movl -12(%rbp), %eax
    jmp .L_end_safety_check
    movl $0, %eax
    movl %eax, -36(%rbp)
    movl -36(%rbp), %eax
    jmp .L_end_safety_check
.L_end_safety_check:
    movq %rbp, %rsp
    popq %rbp
    ret
.globl weight_sum
weight_sum:
    pushq %rbp
    movq %rsp, %rbp
    subq $48, %rsp
.L_weight_sum_0:
    movl %edi, %eax
    movl %eax, -4(%rbp)
    movl %esi, %eax
    movl %eax, -8(%rbp)
    movl -8(%rbp), %ecx
    movl -4(%rbp), %eax
    cmpl %ecx, %eax
    setg %al
    movzbl %al, %eax
    movl %eax, -20(%rbp)
    movl -20(%rbp), %eax
    imull -4(%rbp), %eax
    movl %eax, -24(%rbp)
    movl -8(%rbp), %ecx
    movl -4(%rbp), %eax
    cmpl %ecx, %eax
    setle %al
    movzbl %al, %eax
    movl %eax, -28(%rbp)
    movl -28(%rbp), %eax
    imull -8(%rbp), %eax
    movl %eax, -32(%rbp)
    movl -24(%rbp), %eax
    addl -32(%rbp), %eax
    movl %eax, -36(%rbp)
    movl -36(%rbp), %eax
    movl %eax, -12(%rbp)
    movl -12(%rbp), %eax
    jmp .L_end_weight_sum
    movl $0, %eax
    movl %eax, -40(%rbp)
    movl -40(%rbp), %eax
    jmp .L_end_weight_sum
.L_end_weight_sum:
    movq %rbp, %rsp
    popq %rbp
    ret
.globl main
main:
    pushq %rbp
    movq %rsp, %rbp
    subq $160, %rsp
.L_main_0:
    movl $0, %eax
    movl %eax, -44(%rbp)
    movl -44(%rbp), %eax
    movl %eax, -4(%rbp)
    movl $42, %eax
    movl %eax, -48(%rbp)
    movl -48(%rbp), %eax
    movl %eax, -8(%rbp)
    movl $1, %eax
    movl %eax, -52(%rbp)
    movl -52(%rbp), %eax
    movl %eax, -12(%rbp)
    movl $10, %eax
    movl %eax, -56(%rbp)
    movl -56(%rbp), %eax
    movl %eax, -16(%rbp)
    movl $100, %eax
    movl %eax, -60(%rbp)
    movl -60(%rbp), %eax
    movl %eax, -20(%rbp)
    movl -20(%rbp), %eax
    movl %eax, -4(%rbp)
    movl -4(%rbp), %eax
    addl -16(%rbp), %eax
    movl %eax, -64(%rbp)
    movl -64(%rbp), %eax
    movl %eax, -4(%rbp)
    movl -4(%rbp), %eax
    addl -12(%rbp), %eax
    movl %eax, -68(%rbp)
    movl -68(%rbp), %eax
    movl %eax, -4(%rbp)
    movl $0, %eax
    movl %eax, -72(%rbp)
    movl -72(%rbp), %eax
    movl %eax, -28(%rbp)
    movl -8(%rbp), %eax
    movl %eax, %edi
    movl -4(%rbp), %eax
    movl %eax, %esi
    call weight_sum
    movl %eax, -80(%rbp)
    movl $0, %eax
    movl %eax, -84(%rbp)
    movl -84(%rbp), %ecx
    movl -80(%rbp), %eax
    cmpl %ecx, %eax
    setg %al
    movzbl %al, %eax
    movl %eax, -88(%rbp)
    movl -88(%rbp), %eax
    cmpl $0, %eax
    jne .L_main_2
    jmp .L_main_1
.L_main_1:
    movl $1, %eax
    movl %eax, -92(%rbp)
    movl -28(%rbp), %ecx
    movl -92(%rbp), %eax
    cltd
    idivl %ecx
    movl %eax, -96(%rbp)
    movl $0, %eax
    movl %eax, -100(%rbp)
    movl -100(%rbp), %ecx
    movl -96(%rbp), %eax
    cmpl %ecx, %eax
    sete %al
    movzbl %al, %eax
    movl %eax, -104(%rbp)
    movl -104(%rbp), %eax
    cmpl $0, %eax
    jne .L_main_2
    jmp .L_main_3
.L_main_2:
    movl $1, %eax
    movl %eax, -76(%rbp)
    jmp .L_main_4
.L_main_3:
    movl $0, %eax
    movl %eax, -76(%rbp)
    jmp .L_main_4
.L_main_4:
    movl -76(%rbp), %eax
    cmpl $0, %eax
    je .L_main_6
    jmp .L_main_5
.L_main_5:
    movl $2, %eax
    movl %eax, -108(%rbp)
    movl $10, %eax
    movl %eax, -112(%rbp)
    movl $0, %eax
    movl %eax, -116(%rbp)
    movl -112(%rbp), %eax
    movl %eax, %edi
    movl -116(%rbp), %eax
    movl %eax, %esi
    call safety_check
    movl %eax, -120(%rbp)
    movl -120(%rbp), %eax
    movl %eax, -40(%rbp)
    movl -40(%rbp), %eax
    cltq
    movl -4(%rbp), %ecx
    movl %ecx, -36(%rbp, %rax, 4)
    movl $0, %eax
    movl %eax, -124(%rbp)
    movl -124(%rbp), %eax
    cltq
    movl -36(%rbp, %rax, 4), %ecx
    movl %ecx, -128(%rbp)
    movl $11, %eax
    movl %eax, -132(%rbp)
    movl -128(%rbp), %eax
    subl -132(%rbp), %eax
    movl %eax, -136(%rbp)
    movl -136(%rbp), %eax
    jmp .L_end_main
    jmp .L_main_6
.L_main_6:
    movl $1, %eax
    movl %eax, -140(%rbp)
    movl -140(%rbp), %eax
    negl %eax
    movl %eax, -144(%rbp)
    movl -144(%rbp), %eax
    jmp .L_end_main
    movl $0, %eax
    movl %eax, -148(%rbp)
    movl -148(%rbp), %eax
    jmp .L_end_main
.L_end_main:
    movq %rbp, %rsp
    popq %rbp
    ret
