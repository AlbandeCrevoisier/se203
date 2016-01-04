AS = arm-none-eabi-as
ASFLAGS = -g -mcpu=cortex-m0plus

CC = arm-none-eabi-gcc
CFLAGS = -g -O1 -mcpu=cortex-m0plus -mthumb -Wall -Wextra -Werror -Wpedantic -std=c99

LD = arm-none-eabi-gcc
LDFLAGS = -T ld_ram.lds -nostdlib

OBJ = crt0.o init.o loop.o fibo.o

.PHONY: clean jl

fibo: crt0.o init.o fibo.o
	$(LD) $(LDFLAGS) $^ -o fibo

clean :
	rm $(OBJ)

jl :
	JLinkGDBServer -if swd -device "MKL46Z256xxx4" -LocalhostOnly
