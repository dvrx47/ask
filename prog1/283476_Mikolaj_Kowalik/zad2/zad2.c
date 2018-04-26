#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	unsigned long lcm, gcd;
} result_t;

result_t lcm_gcd(unsigned long, unsigned long);

int main(int argc, char **argv)
{
	if( argc != 3 ) return 1;
	unsigned long a1 = atol(argv[1]);
	unsigned long a2 = atol(argv[2]);
	result_t res = lcm_gcd(a1, a2);
	printf("lcm = %ld\ngcd = %ld\n", res.lcm, res.gcd);
	return 0;
}
