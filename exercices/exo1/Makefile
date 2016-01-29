CC=arm-none-eabi-gcc
CFLAGS=-Wall -Werror -Wextra -Wpedantic -c

#object
o:
	$(CC) $(CFLAGS) -o code.o code.c

#clean
c:
	rm *.o

#dump object
d:
	arm-none-eabi-objdump -t code.o
