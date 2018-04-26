zad2: zad2.o lcm_gcd.o
	gcc -g -ggdb zad2.o lcm_gcd.o -o zad2

zad2.o: zad2.c
	gcc -c -g -ggdb zad2.c -o zad2.o

lcm_gcd.o: lcm_gcd.s
	as -g -ggdb lcm_gcd.s -o lcm_gcd.o

clean:
	rm -f *.o zad2
