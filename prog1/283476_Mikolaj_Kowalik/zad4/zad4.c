#include <stdio.h>
#include <stdlib.h>

unsigned long fibonacci(unsigned long n);

int main(int argc, char **argv)
{
	unsigned long n = atol(argv[1]);
	printf("fibonacci(%ld) = %ld\n", n, fibonacci(n));
	return 0;
}
