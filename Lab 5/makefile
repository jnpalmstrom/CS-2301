all: etest etest-testmode

etest: etest.o
	gcc -g etest.o -o etest

etest.o: etest.c etest.h
	gcc -g -c --std=gnu89 etest.c

etest-testmode: etest-testmode.o
	gcc -g etest-testmode.o -o etest-testmode

etest-testmode.o: etest.c etest.h
	gcc -g -c --std=gnu89 -DTESTMODE etest.c  -o etest-testmode.o

clean:
	rm -f *.o etest etest-testmode

docs:
	doxygen
	chmod a+r html/*
	cp -p html/* ~/public_html/cs2301assig5
	chmod a=rx etest.txt
