.globl clz
.text

clz:
    lzcnt %edi, %eax
	ret;
