.LC0:
        .string "%lld"
.LC1:
        .string "1"
main:
        stp     x29, x30, [sp, -32]!
        mov     x29, sp
        add     x0, sp, 24
        mov     x1, x0
        adrp    x0, .LC0
        add     x0, x0, :lo12:.LC0
        bl      __isoc99_scanf
        b       .L2
.L4:
        ldr     x0, [sp, 24]
        mov     x1, x0
        adrp    x0, .LC0
        add     x0, x0, :lo12:.LC0
        bl      printf
        ldr     x0, [sp, 24]
        and     x0, x0, 1
        cmp     x0, 0
        beq     .L3
        ldr     x1, [sp, 24]
        mov     x0, x1
        lsl     x0, x0, 1
        add     x0, x0, x1
        add     x0, x0, 1
        str     x0, [sp, 24]
        b       .L2
.L3:
        ldr     x0, [sp, 24]
        lsr     x1, x0, 63
        add     x0, x1, x0
        asr     x1, x0, 1
        mov     x0, x1
        str     x0, [sp, 24]
.L2:
        ldr     x0, [sp, 24]
        cmp     x0, 1
        bne     .L4
        adrp    x0, .LC1
        add     x0, x0, :lo12:.LC1
        bl      puts
        mov     w0, 0
        ldp     x29, x30, [sp], 32
        ret