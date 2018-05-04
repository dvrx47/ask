.globl clz
.text

clz:
	jmp reverse;
clz1:
	xorq %rsi, %rsi;
	movq $1, %rcx;
	orq %rdi, %rdi;
	je nzero;

petla:
	cmpq %rsi, %rcx;
	jne dalej;
	movq %rsi, %rax;
	ret;

dalej:
	movq %rdi, %rdx;
	sarq %cl, %rdx;
	salq %cl, %rdx;
	cmpq %rdi, %rdx;
	je ze;
	addq %rsi, %rcx;
	sarq $1, %rcx;
	jmp petla;

ze:
	movq %rcx, %rsi;
	salq $1, %rcx;
	jmp dalej;

nzero:
	movq $32, %rax;
	ret;

reverse:
	movl %edi, %esi;
	andl $0xAAAAAAAA, %edi;
	andl $0x55555555, %esi;
	shrl $1, %edi;
	shll $1, %esi;
	orl  %esi, %edi;

	movl %edi, %esi;
	andl $0xcccccccc, %edi;
	andl $0x33333333, %esi;
	shrl $2, %edi;
	shll $2, %esi;
	orl  %esi, %edi;

	movl %edi, %esi;
	andl $0xf0f0f0f0, %edi;
	andl $0x0f0f0f0f, %esi;
	shrl $4, %edi;
	shll $4, %esi;
	orl  %esi, %edi;

	movl %edi, %esi;
	andl $0xff00ff00, %edi;
	andl $0x00ff00ff, %esi;
	shrl $8, %edi;
	shll $8, %esi;
	orl  %esi, %edi;
	rorl $16, %edi;
	jmp clz1;
