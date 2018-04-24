#include <stdio.h>
#include <stdlib.h>

void insert_sort(long *first, long *last);

int main(int argc, char **argv)
{
	int n = atoi(argv[1]);
	long tab[n];
	for( int i = 0; i<n; ++i )
		tab[i] = rand()%100;
	insert_sort( &tab[0], &tab[n-1] );
	for( int i=0; i<n; ++i ) printf("%ld, ", tab[i] );
	printf("\n");
	return 0;
}
