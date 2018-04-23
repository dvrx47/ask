zad1: zad1.o clz.o
	gcc zad1.o clz.o -o zad1

zad1.o: zad1.c
	gcc -c zad1.c -o zad1.o

clz.o: clz.s
	as clz.s -o clz.o

clean:
	rm -f *.o zad1
