.globl main
main:
    pushq %rbp
    movq %rsp, %rbp
    subq $16, %rsp
.L_main_entry:
    movl $8, %eax
    movl %eax, -12(%rbp)
    movl -12(%rbp), %eax
    movl %eax, -4(%rbp)
    movl -4(%rbp), %eax
    jmp end_main
end_main:
    movq %rbp, %rsp
    popq %rbp
    ret
