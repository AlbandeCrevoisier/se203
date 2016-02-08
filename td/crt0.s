.thumb
.global _start
.thumb_func
_start:
	LDR R0, =_stack_top
	MOV SP, R0
	BL init_bss
	BL main
loop:
	BL loop
