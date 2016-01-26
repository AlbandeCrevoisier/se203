AS = arm-none-eabi-as
ASFLAGS = -g -mcpu=cortex-m0plus

CC = arm-none-eabi-gcc
CFLAGS = -g -O1 -mcpu=cortex-m0plus -mthumb -Wall -Wextra -Werror -Wpedantic -std=gnu99

LD = arm-none-eabi-gcc
LDFLAGS = -T ld_ram.lds -nostdlib

INIT = crt0.o init.o clocks.o

vpath %.h led uart clocks matrix
vpath %.c init loop fibo led uart matrix
vpath %.s  init
vpath %.o clocks

SRC = led.c led_main.c uart.c uart_main.c matrix.c matrix_main.c

.PHONY: clean jl

matrix_main : $(INIT) matrix.o matrix_main.o

uart_main : $(INIT) uart.o uart_main.o

led_main : $(INIT) led.o led_main.o

include $(SRC:.c=.d)

%.d : %.c
	$(CC) $(CFLAGS) -MM -MF $@ -MP $<

jl :
	JLinkGDBServer -if swd -device "MKL46Z256xxx4" -LocalhostOnly

clean :
	rm *.o
	rm *.d
	rm *_main
