#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int8_t a = 42;
int16_t b = 42;
int32_t c = 42;
int64_t d = 42;
int64_t e = 42;
int32_t f = 42;
int16_t g = 42;
int8_t h = 42;
int8_t foo;
int16_t bar;
int32_t baz;

const char msg[] = "Hello world!\n";

int
main()
{
	baz = 1337;
	int x = 42;
	printf("%d\n", x);
	int *y = malloc(sizeof(int));
	printf("%ldu\n", sizeof(y));

	return 0;
}
