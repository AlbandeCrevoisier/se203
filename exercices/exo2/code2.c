#include <stdio.h>
#include <unistd.h>

int
main ()
{
	int x = 42;
	printf("parent %p\n", (void *) &x);
	int f = fork();
	if (f == 0) {
		int y = 1337;
		printf("child %p\n", (void *) &y);
	}

    return 0;
}

