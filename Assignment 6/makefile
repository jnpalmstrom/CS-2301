all: tnoderandom tnodetest stacktest queuetest

tnoderandom: tnoderandom.o tnode.o
	gcc -g --std=gnu89 tnoderandom.o tnode.o -o tnoderandom

tnoderandom.o: tnoderandom.c tnode.h
	gcc -g -c --std=gnu89 tnoderandom.c

tnodetest: tnodetest.o tnode.o
	gcc -g --std=gnu89 tnodetest.o tnode.o -o tnodetest

tnodetest.o: tnodetest.c tnode.h
	gcc -g -c --std=gnu89 tnodetest.c

tnode.o: tnode.c tnode.h
	gcc -g -c --std=gnu89 tnode.c

queuetest: queuetest.o queue.o
	gcc -g --std=gnu89 queuetest.o queue.o -o queuetest

queue.o: queue.c queue.h
	gcc -g -c --std=gnu89 queue.c

queuetest.o: queuetest.c queue.h
	gcc -g -c --std=gnu89 queuetest.c

stacktest: stacktest.o stack.o
	gcc -g --std=gnu89 stacktest.o stack.o -o stacktest

stack.o: stack.c stack.h
	gcc -g -c --std=gnu89 stack.c

stacktest.o: stacktest.c stack.h
	gcc -g -c --std=gnu89 stacktest.c

docs:
	doxygen
	chmod a+r html/*
	cp -p html/* ~/public_html/cs2301assig6

clean:
	rm -f *.o
	rm -f stacktest queuetest tnodetest tnoderandom
