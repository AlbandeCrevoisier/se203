AS = arm-none-eabi-as
ASFLAGS = -g -mcpu=cortex-m0plus

CC = arm-none-eabi-gcc
CFLAGS = -g -O1 -mcpu=cortex-m0plus -mthumb -Wall -Wextra -Werror -Wpedantic -std=gnu99

LD = arm-none-eabi-gcc
LDFLAGS = -T ld_ram.lds -nostdlib

SRC = main.c matrix.c irq.c buttons.c
PRECIOUS_OBJS = clocks.o
OBJS = crt0.o init.o flash.o main.o matrix.o irq.o buttons.o image.o

EXE = main

.PHONY: clean jl

$(EXE) : $(OBJS) $(PRECIOUS_OBJS)

image.o : image.raw
	arm-none-eabi-objcopy -I binary -O elf32-littlearm -B arm image.raw image.o

-include $(SRC:.c=.d)

%.d : %.c
	$(CC) $(CFLAGS) -MM -MF $@ -MP $<

jl :
	JLinkGDBServer -if swd -device "MKL46Z256xxx4" -LocalhostOnly

clean :
	rm -f $(OBJS)
	rm -f *.d
	rm -f $(EXE)
