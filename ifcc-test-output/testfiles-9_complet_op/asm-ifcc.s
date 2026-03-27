.globl main
main:
    pushq %rbp
    movq %rsp, %rbp
    subq $400, %rsp
.L_main_0:
    movl $10, %eax
    movl %eax, -84(%rbp)
    movl $2, %eax
    movl %eax, -88(%rbp)
    movl $15, %eax
    movl %eax, -92(%rbp)
    movl -92(%rbp), %eax
    movl %eax, -4(%rbp)
    movl $4, %eax
    movl %eax, -96(%rbp)
    movl -96(%rbp), %eax
    movl %eax, -8(%rbp)
    movl $2, %eax
    movl %eax, -100(%rbp)
    movl -100(%rbp), %eax
    movl %eax, -12(%rbp)
    movl -4(%rbp), %eax
    imull -8(%rbp), %eax
    movl %eax, -104(%rbp)
    movl $3, %eax
    movl %eax, -108(%rbp)
    movl -108(%rbp), %ecx
    movl -12(%rbp), %eax
    sall %cl, %eax
    movl %eax, -112(%rbp)
    movl -104(%rbp), %eax
    addl -112(%rbp), %eax
    movl %eax, -116(%rbp)
    movl -12(%rbp), %ecx
    movl -4(%rbp), %eax
    cltd
    idivl %ecx
    movl %eax, -120(%rbp)
    movl -120(%rbp), %eax
    notl %eax
    movl %eax, -124(%rbp)
    movl $255, %eax
    movl %eax, -128(%rbp)
    movl -124(%rbp), %eax
    andl -128(%rbp), %eax
    movl %eax, -132(%rbp)
    movl -116(%rbp), %eax
    xorl -132(%rbp), %eax
    movl %eax, -136(%rbp)
    movl $100, %eax
    movl %eax, -140(%rbp)
    movl $1, %eax
    movl %eax, -144(%rbp)
    movl -144(%rbp), %ecx
    movl -140(%rbp), %eax
    sarl %cl, %eax
    movl %eax, -148(%rbp)
    movl -136(%rbp), %eax
    orl -148(%rbp), %eax
    movl %eax, -152(%rbp)
    movl -152(%rbp), %eax
    movl %eax, -16(%rbp)
    movl $0, %eax
    movl %eax, -156(%rbp)
    movl $1, %eax
    movl %eax, -160(%rbp)
    movl -156(%rbp), %eax
    cltq
    movl -160(%rbp), %ecx
    movl %ecx, -56(%rbp, %rax, 4)
    movl $1, %eax
    movl %eax, -164(%rbp)
    movl $5, %eax
    movl %eax, -168(%rbp)
    movl -164(%rbp), %eax
    cltq
    movl -168(%rbp), %ecx
    movl %ecx, -56(%rbp, %rax, 4)
    movl $2, %eax
    movl %eax, -172(%rbp)
    movl $8, %eax
    movl %eax, -176(%rbp)
    movl -172(%rbp), %eax
    cltq
    movl -176(%rbp), %ecx
    movl %ecx, -56(%rbp, %rax, 4)
    movl $0, %eax
    movl %eax, -180(%rbp)
    movl -180(%rbp), %eax
    cltq
    movl -56(%rbp, %rax, 4), %ecx
    movl %ecx, -184(%rbp)
    movl -4(%rbp), %eax
    addl -8(%rbp), %eax
    movl %eax, -188(%rbp)
    movl -184(%rbp), %eax
    cltq
    movl -188(%rbp), %ecx
    movl %ecx, -56(%rbp, %rax, 4)
    movl $1, %eax
    movl %eax, -192(%rbp)
    movl -192(%rbp), %eax
    cltq
    movl -56(%rbp, %rax, 4), %ecx
    movl %ecx, -196(%rbp)
    movl $17, %eax
    movl %eax, -200(%rbp)
    movl -196(%rbp), %eax
    subl -200(%rbp), %eax
    movl %eax, -204(%rbp)
    movl $2, %eax
    movl %eax, -208(%rbp)
    movl -208(%rbp), %eax
    cltq
    movl -56(%rbp, %rax, 4), %ecx
    movl %ecx, -212(%rbp)
    movl -212(%rbp), %eax
    imull -12(%rbp), %eax
    movl %eax, -216(%rbp)
    movl -204(%rbp), %eax
    cltq
    movl -216(%rbp), %ecx
    movl %ecx, -56(%rbp, %rax, 4)
    movl $100, %eax
    movl %eax, -220(%rbp)
    movl -220(%rbp), %eax
    movl %eax, -68(%rbp)
    movl $2, %eax
    movl %eax, -224(%rbp)
    movl -224(%rbp), %ecx
    movl -68(%rbp), %eax
    cltd
    idivl %ecx
    movl %eax, -228(%rbp)
    movl -228(%rbp), %eax
    movl %eax, -72(%rbp)
    movl -16(%rbp), %eax
    addl -72(%rbp), %eax
    movl %eax, -232(%rbp)
    movl -232(%rbp), %eax
    movl %eax, -16(%rbp)
    movl $1000, %eax
    movl %eax, -236(%rbp)
    movl -236(%rbp), %eax
    movl %eax, -76(%rbp)
    movl -16(%rbp), %eax
    subl -76(%rbp), %eax
    movl %eax, -240(%rbp)
    movl -240(%rbp), %eax
    addl -68(%rbp), %eax
    movl %eax, -244(%rbp)
    movl -244(%rbp), %eax
    movl %eax, -16(%rbp)
    movl -8(%rbp), %ecx
    movl -4(%rbp), %eax
    cmpl %ecx, %eax
    setg %al
    movzbl %al, %eax
    movl %eax, -252(%rbp)
    movl -252(%rbp), %eax
    cmpl $0, %eax
    je .L_main_3
    jmp .L_main_1
.L_main_1:
    movl $2, %eax
    movl %eax, -260(%rbp)
    movl -260(%rbp), %ecx
    movl -12(%rbp), %eax
    cmpl %ecx, %eax
    sete %al
    movzbl %al, %eax
    movl %eax, -264(%rbp)
    movl -264(%rbp), %eax
    cmpl $0, %eax
    jne .L_main_6
    jmp .L_main_5
.L_main_5:
    movl $0, %eax
    movl %eax, -268(%rbp)
    movl -268(%rbp), %ecx
    movl -16(%rbp), %eax
    cmpl %ecx, %eax
    setl %al
    movzbl %al, %eax
    movl %eax, -272(%rbp)
    movl -272(%rbp), %eax
    cmpl $0, %eax
    jne .L_main_6
    jmp .L_main_7
.L_main_6:
    movl $1, %eax
    movl %eax, -256(%rbp)
    jmp .L_main_8
.L_main_7:
    movl $0, %eax
    movl %eax, -256(%rbp)
    jmp .L_main_8
.L_main_8:
    movl -256(%rbp), %eax
    cmpl $0, %eax
    je .L_main_3
    jmp .L_main_2
.L_main_2:
    movl $1, %eax
    movl %eax, -248(%rbp)
    jmp .L_main_4
.L_main_3:
    movl $0, %eax
    movl %eax, -248(%rbp)
    jmp .L_main_4
.L_main_4:
    movl -248(%rbp), %eax
    cmpl $0, %eax
    je .L_main_11
    jmp .L_main_9
.L_main_9:
    movl $0, %eax
    movl %eax, -276(%rbp)
    movl -276(%rbp), %ecx
    movl -16(%rbp), %eax
    cmpl %ecx, %eax
    sete %al
    movzbl %al, %eax
    movl %eax, -280(%rbp)
    movl -280(%rbp), %eax
    cmpl $0, %eax
    sete %al
    movzbl %al, %eax
    movl %eax, -284(%rbp)
    movl -284(%rbp), %eax
    cmpl $0, %eax
    je .L_main_14
    jmp .L_main_12
.L_main_12:
    movl $0, %eax
    movl %eax, -288(%rbp)
    movl $42, %eax
    movl %eax, -292(%rbp)
    movl -288(%rbp), %eax
    cltq
    movl -292(%rbp), %ecx
    movl %ecx, -64(%rbp, %rax, 4)
    jmp .L_main_13
.L_main_14:
    movl $0, %eax
    movl %eax, -296(%rbp)
    movl $0, %eax
    movl %eax, -300(%rbp)
    movl -296(%rbp), %eax
    cltq
    movl -300(%rbp), %ecx
    movl %ecx, -64(%rbp, %rax, 4)
    jmp .L_main_13
.L_main_13:
    jmp .L_main_10
.L_main_11:
    movl $0, %eax
    movl %eax, -304(%rbp)
    movl $1, %eax
    movl %eax, -308(%rbp)
    movl -304(%rbp), %eax
    cltq
    movl -308(%rbp), %ecx
    movl %ecx, -64(%rbp, %rax, 4)
    jmp .L_main_10
.L_main_10:
    movl $1, %eax
    movl %eax, -312(%rbp)
    movl -8(%rbp), %ecx
    movl -4(%rbp), %eax
    cmpl %ecx, %eax
    setne %al
    movzbl %al, %eax
    movl %eax, -316(%rbp)
    movl $10, %eax
    movl %eax, -320(%rbp)
    movl -320(%rbp), %ecx
    movl -12(%rbp), %eax
    cmpl %ecx, %eax
    setle %al
    movzbl %al, %eax
    movl %eax, -324(%rbp)
    movl $100, %eax
    movl %eax, -328(%rbp)
    movl -328(%rbp), %ecx
    movl -16(%rbp), %eax
    cmpl %ecx, %eax
    setg %al
    movzbl %al, %eax
    movl %eax, -332(%rbp)
    movl -324(%rbp), %eax
    andl -332(%rbp), %eax
    movl %eax, -336(%rbp)
    movl -316(%rbp), %eax
    xorl -336(%rbp), %eax
    movl %eax, -340(%rbp)
    movl -312(%rbp), %eax
    cltq
    movl -340(%rbp), %ecx
    movl %ecx, -64(%rbp, %rax, 4)
    movl $0, %eax
    movl %eax, -344(%rbp)
    movl -344(%rbp), %eax
    cltq
    movl -64(%rbp, %rax, 4), %ecx
    movl %ecx, -348(%rbp)
    movl $1, %eax
    movl %eax, -352(%rbp)
    movl -352(%rbp), %eax
    cltq
    movl -64(%rbp, %rax, 4), %ecx
    movl %ecx, -356(%rbp)
    movl -348(%rbp), %eax
    addl -356(%rbp), %eax
    movl %eax, -360(%rbp)
    movl $2, %eax
    movl %eax, -364(%rbp)
    movl -364(%rbp), %eax
    cltq
    movl -56(%rbp, %rax, 4), %ecx
    movl %ecx, -368(%rbp)
    movl -360(%rbp), %eax
    addl -368(%rbp), %eax
    movl %eax, -372(%rbp)
    movl $14, %eax
    movl %eax, -376(%rbp)
    movl -4(%rbp), %eax
    subl -376(%rbp), %eax
    movl %eax, -380(%rbp)
    movl -372(%rbp), %eax
    imull -380(%rbp), %eax
    movl %eax, -384(%rbp)
    movl -384(%rbp), %eax
    jmp .L_end_main
    movl $0, %eax
    movl %eax, -388(%rbp)
    movl -388(%rbp), %eax
    jmp .L_end_main
.L_end_main:
    movq %rbp, %rsp
    popq %rbp
    ret
