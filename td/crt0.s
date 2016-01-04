.thumb
.global _start
_start:
	LDR R0, =0x1fffffff
	MOV SP, R0
	BL init_bss
	BL main
