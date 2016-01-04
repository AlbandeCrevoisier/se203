CC = arm-none-eabi-gcc
CFLAGS = -g -O1 -mcpu=cortex-m0plus -mthumb -Wall -Wextra -Werror -Wpedantic -std=c99

LD = arm-none-eabi-gcc
LDFLAGS = -T ld_ram.lds -nostdlib

.PHONY: clean jl JLinkGDBServer -if swd -device "MKL46Z256xxx4" -LocalhostOnly

clean :
	rm -f *.o
