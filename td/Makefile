CC = arm-none-eabi-gcc
CFLAGS = -c -g -O1 -mcpu=cortex-m0plus -mthumb -Wall -Wextra -Werror -Wpedantic

LD = arm-none-eabi-gcc
LDFLAGS = -T ld_ram.lds

.PHONY: clean

clean :
	rm -f *.o
