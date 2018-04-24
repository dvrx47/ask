.globl insert_sort
.text

insert_sort:
	movq %rdi, %rdx; 

while1:	
	cmpq %rdx, %rsi;
	je koniec;
	movq 8(%rdx), %r8;
	cmpq %r8, (%rdx);
	je zwieksz;
	js zwieksz;
	movq 8(%rdx), %rcx;
	movq %rdx, %r8;

while2:
	cmpq (%r8), %rcx;
	jns enwhile2;
	cmpq %rdi, %r8;
	jns elif;
	movq %rcx, (%rdi);
	jmp while1;

elif:
	movq (%r8), %r9;
	movq %r9, 8(%r8);
	subq $8, %r8;
	jmp while2;

zwieksz:
	addq $8, %rdx;
	jmp while1;

enwhile2:
	movq %rcx, 8(%r8);
	addq $8, %rdx;
	jmp while1; 

koniec:
	ret;
