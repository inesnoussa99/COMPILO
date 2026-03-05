.globl _main
_main:
    stp x29, x30, [sp, #-16]!
    mov x29, sp
    sub sp, sp, #16
    mov w0, #3
    str w0, [sp, #-16]!
    mov w0, #4
    ldr w1, [sp], #16
    add w0, w1, w0
    str w0, [x29, #-4]
    str w0, [x29, #-4]
    add sp, sp, #16
    ldp x29, x30, [sp], #16
    ret
