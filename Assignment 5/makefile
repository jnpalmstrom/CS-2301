all: etest etest-testmode writeTextfile readEmployees binaryWriteTextfile binaryReadEmployees

binaryReadEmployees: binaryReadEmployees.o struct.o
	gcc -g binaryReadEmployees.o struct.o -lreadline -lncurses -o binaryReadEmployees

binaryReadEmployees.o: binaryReadEmployees.c etest.h
	gcc -g -c --std=gnu89 binaryReadEmployees.c

binaryWriteTextfile: binaryWriteTextfile.o struct.o
	gcc -g binaryWriteTextfile.o struct.o -lreadline -lncurses -o binaryWriteTextfile

binaryWriteTextfile.o: binaryWriteTextfile.c etest.h
	gcc -g -c --std=gnu89 binaryWriteTextfile.c

readEmployees: readEmployees.o struct.o
	gcc -g readEmployees.o struct.o -lreadline -lncurses -o readEmployees

readEmployees.o: readEmployees.c etest.h
	gcc -g -c --std=gnu89 readEmployees.c

writeTextfile: writeTextfile.o struct.o
	gcc -g writeTextfile.o struct.o -lreadline -lncurses -o writeTextfile

writeTextfile.o: writeTextfile.c etest.h
	gcc -g -c --std=gnu89 writeTextfile.c

etest: etest.o struct.o
	gcc -g etest.o struct.o -lreadline -lncurses -o etest

etest.o: etest.c etest.h
	gcc -g -c --std=gnu89 etest.c

etest-testmode: etest-testmode.o struct.o
	gcc -g etest-testmode.o struct.o -lreadline -lncurses -o etest-testmode

etest-testmode.o: etest.c etest.h
	gcc -g -c --std=gnu89 -DTESTMODE etest.c  -o etest-testmode.o

struct.o: struct.c etest.h
	gcc -g -c --std=gnu89 struct.c

clean:
	rm -f *.o etest etest-testmode writeTextfile readEmployees binaryWriteTextfile binaryReadEmployees

docs:
	doxygen
	chmod a+r html/*
	cp -p html/* ~/public_html/cs2301assig5
	chmod a=rx etest.txt
