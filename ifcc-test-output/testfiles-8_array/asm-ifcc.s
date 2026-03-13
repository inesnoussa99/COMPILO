.globl main
main:
    pushq %rbp
    movq %rsp, %rbp
    subq $1072, %rsp
    movl $10, %eax
    movl $0, %eax
    movl %eax, -44(%rbp)
    movl -44(%rbp), %eax
    cltq
    movq %rax, -56(%rbp)
    movl $100, %eax
    movl %eax, %ecx
    movq -56(%rbp), %rax
    movl %ecx, -40(%rbp, %rax, 4)
    movl $0, %eax
    cltq
    movl -40(%rbp, %rax, 4), %eax
    jmp end_main
end_main:
    movq %rbp, %rsp
    popq %rbp
    ret
