AS = arm-none-eabi-as
ASFLAGS = -g -mcpu=cortex-m0plus

CC = arm-none-eabi-gcc
CFLAGS = -g -O1 -mcpu=cortex-m0plus -mthumb -Wall -Wextra -Werror -Wpedantic -std=gnu99

LD = arm-none-eabi-gcc
LDFLAGS = -T ld_ram.lds -nostdlib
LOADLIBES += crt0.o init.o

vpath %.h led uart clocks
vpath %.c init loop fibo led uart
vpath %.s  init
vpath %.o clocks

SRC = led.c led_main.c uart.c uart_main.c

.PHONY: clean jl

uart_main : crt0.o init.o clocks.o uart.o uart_main.o
	$(LD) $(LDFLAGS) $^ -o uart_main

led_main : crt0.o init.o led_main.o led.o
	$(LD) $(LDFLAGS) $^ -o led_main

include $(SRC:.c=.d)

%.d : %.c
	$(CC) $(CFLAGS) -MM -MF $@ -MP $<

jl :
	JLinkGDBServer -if swd -device "MKL46Z256xxx4" -LocalhostOnly

clean :
	rm *.o
	rm led_main
	rm uart_main
