.globl lcm_gcd
.text

lcm_gcd:
	movq %rdi, %rdx;
	movq %rsi, %rcx;

while1:
	cmpq %rcx, %rdx;
	je lcm;
	js a1lta2;
	addq %rsi, %rcx;
	jmp while1;

a1lta2:
	addq %rdi, %rdx;
	jmp while1;

lcm:
	movq %rdx, %rax;
	movq %rdi, %rdx;
	movq %rsi, %rcx;

while2:
	cmpq %rcx, %rdx;
	je gcd;
	js a1gta2;
	subq %rcx, %rdx;
	jmp while2;

a1gta2:
	subq %rdx, %rcx;
	jmp while2;

gcd:
	ret;
