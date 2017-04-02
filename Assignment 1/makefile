all: lab1 num leap

lab1: lab1.o
	gcc lab1.o -o lab1

lab1.o: lab1.c
	gcc -c lab1.c

num: num.o average.o
	gcc num.o average.o -o num

num.o: num.c average.o
	gcc -c num.c

leap: leap.o
	gcc leap.o -o leap

leap.o: leap.c
	gcc -c leap.c

average: average.o
	gcc average.o -o average

average.o: average.c average.h
	gcc -c average.c
clean:
	rm -f lab1.o lab1 num.o num leap.o leap average.o average
