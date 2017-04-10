ctest: ctest.o mystring.o employee.o
	gcc ctest.o mystring.o employee.o -o ctest

ctest.o: ctest.c mystring.h
	gcc -c ctest.c

mystring.o: mystring.c mystring.h
	gcc -c mystring.c

employee.o: employee.c employee.h
	gcc -g -c employee.c

clean: 
	rm -f mystring.o ctest.o employee.o ctest

docs:
	doxygen
	chmod go+r html/*
	cp html/* ~/public_html/cs2301assig3
