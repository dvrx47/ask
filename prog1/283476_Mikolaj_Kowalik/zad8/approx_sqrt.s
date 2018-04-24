        .global approx_sqrt
        .text
approx_sqrt: 
		movsd %xmm1, %xmm2;
		
	while1:
		movsd %xmm0, %xmm3;
		movsd %xmm2, %xmm4;
		mulsd %xmm4, %xmm4;
		subsd %xmm4, %xmm3;
		ucomisd %xmm1, %xmm3;
		ja rob;
		
		movsd %xmm2, %xmm3;
		mulsd %xmm3, %xmm3;
		subsd %xmm0, %xmm3;
		ucomisd %xmm1, %xmm3;
		ja rob;
		jmp end;
		rob:
		movsd %xmm2, %xmm3;
		movsd %xmm0, %xmm4;
		divsd %xmm3, %xmm4;
		addsd %xmm4, %xmm2;
		mulsd half, %xmm2;
		jmp while1;
		
end:
		movsd %xmm2, %xmm0;
		ret;
		
        
.section .rodata
half: 	  .double 0.5
