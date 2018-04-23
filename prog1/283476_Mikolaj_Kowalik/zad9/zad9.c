#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

long ZERO = 0;
long L_MAX = LONG_MAX;
long L_MIN = LONG_MIN;

 long adds(long x,long y) {
	asm("mov %rdi, %rax;\
		add %rsi, %rax;\
		cmovo L_MAX, %rax;\
		cmp ZERO, %rdi; \
		setl %r8b; \
		cmp ZERO, %rsi; \
		setl %r9b; \
		cmp ZERO, %rax; \
		setg %r10b; \
		test %r9b, %r10b; \
		cmove ZERO, %r8; \
		test %r8b, %r10b; \
		cmovne L_MIN, %rax;"
	);
}

int main(int argc, char **argv) {
	long a = atol(argv[1]);
	long b = atol(argv[2]);
	printf("%ld\n", adds(a, b));
    return 0;
}
