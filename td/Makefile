AS = arm-none-eabi-as
ASFLAGS = -g -mcpu=cortex-m0plus

CC = arm-none-eabi-gcc
CFLAGS = -g -O1 -mcpu=cortex-m0plus -mthumb -Wall -Wextra -Werror -Wpedantic -std=gnu99

LD = arm-none-eabi-gcc
LDFLAGS = -T ld_ram.lds -nostdlib

INIT = crt0.o init.o clocks.o

SRC = main.c matrix.c
OBJ = $(SRC:.c=.o) image.o crt0.o init.o

.PHONY: clean jl

main : $(INIT) matrix.o main.o image.o

image.o : image.raw
	arm-none-eabi-objcopy -I binary -O elf32-littlearm -B arm image.raw image.o

-include $(SRC:.c=.d)

%.d : %.c
	$(CC) $(CFLAGS) -MM -MF $@ -MP $<

jl :
	JLinkGDBServer -if swd -device "MKL46Z256xxx4" -LocalhostOnly

clean :
	-rm $(OBJ)
	rm *.d
	-rm main
