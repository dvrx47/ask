.globl fibonacci
.text

fibonacci:
	xorq %rax, %rax;
	cmpq $2, %rdi;
	js end;
	subq $1, %rdi;
	pushq %rbp;
	pushq %rax;
	movq %rsp, %rbp;
	callq fibonacci;
	pop %rdx;
	pop %rbp;
	addq %rdx, %rax;
	subq $1, %rdi;
	pushq %rbp;
	push %rax;
	movq %rsp, %rbp;
	callq fibonacci;
	addq $2, %rdi;
	pop %rdx;
	pop %rbp;
	addq %rdx, %rax;
	ret;
end:
	addq $1, %rax;
	rep; ret;
