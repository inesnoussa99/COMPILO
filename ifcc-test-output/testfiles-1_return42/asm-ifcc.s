.globl main
main:
    pushq %rbp
    movq %rsp, %rbp
    subq $1024, %rsp
    movl $42, %eax
    jmp end_main
end_main:
    movq %rbp, %rsp
    popq %rbp
    ret
