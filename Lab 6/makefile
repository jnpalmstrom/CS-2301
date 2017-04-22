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
	rm -f stacktest
