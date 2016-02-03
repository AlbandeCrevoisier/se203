.thumb
.global _start
_start:
    LDR R0, =stack_top
    MOV SP, R0
    BL init_bss
    BL main
loop:
    BL loop
