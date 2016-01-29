CC = arm-none-eabi-gcc
CFLAGS = -Wall -Werror -g -O2 -mthumb
CLIBSFLAGS = -g -O2 -mthumb
LD = arm-none-eabi-gcc
LDFLAGS = -Lopt/mylibs -mthumb
LDLIBS = -lm

SRC = $(wildcard *.c)
OBJS = $(SRC:.c=.o)
LIBS = $(wildcard libs/*.c)
LIBSO = $(LIBS:libs/%.c=%.o)
EXE = hello

$(EXE): $(OBJS) $(LIBSO) 
	$(LD) $(LDFLAGS) $^ $(LDLIBS) -o $@

%.o: libs/%.c
	$(CC) $(CLIBSFLAGS) -c -o $@ $^

-include $(SRC:.c=.d)

%.d: %.c
	$(CC) $(CFLAGS) -MM -MF $@ -MP $<

.PHONY: clean

clean:
	rm *.o *.d hello
