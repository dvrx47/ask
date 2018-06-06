/*
 * Binary search vs. heap search.
 *
 * $ ./bsearch -n 22 -l 23 -v 0
 * Time elapsed: 6.364965 seconds.
 * $ ./bsearch -n 22 -l 23 -v 1
 * Time elapsed: 0.898724 seconds.
 */
#include "common.h"

int unused;

void fill(int *arr, int n) {
  /* Yeah, gcc allows that, though it's non-standard extension ;) */
  int icmp(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
  }

  for (int i = 0; i < n; i++)
    arr[i] = rand();

  qsort(arr, n, sizeof(int), icmp);
}

void heapify(int *dst, int *src, int n) {
  for(int i=n+1, first=n>>1, r=1, a=0;   i>0;   i>>=1, first>>=1, r<<=1)
		for(int k=0, h=first;   k<r;    ++k, h+=i) 
			dst[a++] = src[h];
}

bool binary_search(int *arr, int size, int x) {
  do {
    size >>= 1;
    int y = arr[size];
    if (y == x)
      return true;
    if (y < x)
      arr += size + 1;
  } while (size > 0);

  return false;
}

bool heap_search(int *arr, int size, int x) {
	
    int n=0;

	/*
	do{
		int y = arr[n];
		if( !(y^x) ) return true;
		n<<=1;
		n+=(y<x)+1;
	}while( n<size );
	*/
	
	do{
		int y = arr[n];
		if( y == x ) return true;
		n = (y<x)? (n<<1)+2: (n<<1)+1;
	}while( n<size );
	
	return false;
	
}

int main(int argc, char **argv) {
  int opt, exp = -1, times = -1, var = -1;
  bool err = false;

  while ((opt = getopt(argc, argv, "n:t:v:")) != -1) {
    if (opt == 'n')
      exp = atoi(optarg);
    else if (opt == 't')
      times = 1 << atoi(optarg);
    else if (opt == 'v')
      var = atoi(optarg);
    else
      err = true;
  }

  if (err || exp < 0 || times < 0 || var < 0 || var >= 2) {
    fprintf(stderr,
            "Usage: %s -n log2(size) -t log2(times) -v variant\n", argv[0]);
    return 1;
  }

  int n = (1 << exp) - 1;
  int size = n * sizeof(int);
  int *arr = NULL, *tmp = NULL;
 
  unused = posix_memalign((void **)&arr, getpagesize(), size);

  printf("Generate array of 2^%d-1 elements (%d KiB)\n", exp, size >> 10);

  fill(arr, n);
  if (var == 1) {
    unused = posix_memalign((void **)&tmp, getpagesize(), size);
    heapify(tmp, arr, n);
    //free(arr);
    arr = tmp;
  }
  flush_cache();

  printf("Performing %d searches.\n", times);

  _timer_t timer;
  timer_reset(&timer);
  timer_start(&timer);
  for (int i = 0; i < times; i++) {
    if (var == 0) {
      binary_search(arr, n, rand());
    } else {
      heap_search(arr, n, rand());
    }
  }
  timer_stop(&timer);
  timer_print(&timer);

  free(arr);

  return 0;
}
