CFLAGS = -g -ggdb

zad8: zad8.o approx_sqrt.o
	gcc -no-pie -O0 $(CFLAGS) zad8.o approx_sqrt.o -o zad8

zad8.o: zad8.c
	gcc -O0 $(CFLAGS) -c zad8.c -o zad8.o

approx_sqrt.o: approx_sqrt.s
	as $(CFLAGS) approx_sqrt.s -o approx_sqrt.o

clean:
	rm -f *.o zad8
