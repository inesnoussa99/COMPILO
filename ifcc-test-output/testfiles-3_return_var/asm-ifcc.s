.globl main
main:
    pushq %rbp
    movq %rsp, %rbp
    subq $1040, %rsp
    movl $8, %eax
    movl %eax, -4(%rbp)
    movl -4(%rbp), %eax
    jmp end_main
end_main:
    movq %rbp, %rsp
    popq %rbp
    ret
