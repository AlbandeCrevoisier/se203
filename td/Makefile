AS = arm-none-eabi-as
ASFLAGS = -g -mcpu=cortex-m0plus

CC = arm-none-eabi-gcc
CFLAGS = -g -O1 -mcpu=cortex-m0plus -mthumb -Wall -Wextra -Werror -Wpedantic -std=c99

LD = arm-none-eabi-gcc
LDFLAGS = -T ld_ram.lds -nostdlib
LOADLIBES += crt0.o init.o

vpath %.h led
vpath %.c init loop fibo led
vpath %.s  init

.PHONY: clean jl

led_main : led_main.o led.o
	$(LD) $(LDFLAGS) $(LOADLIBES) $^ -o led_main

jl :
	JLinkGDBServer -if swd -device "MKL46Z256xxx4" -LocalhostOnly
