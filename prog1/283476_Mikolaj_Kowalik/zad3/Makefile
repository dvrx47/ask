zad3: zad3.o insert_sort.o
	gcc -g zad3.o insert_sort.o -o zad3

zad3.o: zad3.c
	gcc -c -g -std=c99 zad3.c -o zad3.o

insert_sort.o: insert_sort.s
	as -g insert_sort.s -o insert_sort.o

clean:
	rm -f *.o zad3
