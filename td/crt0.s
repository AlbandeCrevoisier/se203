.thumb
.global _start
_start:
    LDR R0, =0x20000000
    MOV SP, R0
    BL init_bss
    BL main
loop:
    BL loop
