zad4: zad4.o fibonacci.o
	gcc -g zad4.o fibonacci.o -o zad4

zad4.o: zad4.c
	gcc -c -g zad4.c -o zad4.o

fibonacci.o: fibonacci.s
	as -g fibonacci.s -o fibonacci.o

clean:
	rm -f *.o zad4
