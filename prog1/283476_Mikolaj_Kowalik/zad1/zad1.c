#include <stdio.h>
#include <stdlib.h>

int clz(long);

int main(int argc, char **argv)
{
  	printf( "%d\n", clz( atoi( argv[1] ) ) );
  	return 0;
}
