all: at at2 at3

at: at.o print_arrays.o
	gcc -g --std=gnu99 at.o print_arrays.o -o at

at.o: at.c print_arrays.h
	gcc -g --std=gnu99 -c at.c

at2: at2.o print_arrays.o sort.o
	gcc -g --std=gnu99 at2.o print_arrays.o sort.o -o at2

at2.o: at2.c print_arrays.h sort.h
	gcc -g --std=gnu99 -c at2.c

at3: at3.o print_arrays.o sort.o
	gcc -g --std=gnu99 at3.o print_arrays.o sort.o -o at3

at3.o: at3.c print_arrays.h sort.h
	gcc -g --std=gnu99 -c at3.c

print_arrays.o: print_arrays.c print_arrays.h
	gcc -g --std=gnu99 -c print_arrays.c

sort.o: sort.c sort.h
	gcc -g --std=gnu99 -c sort.c

docs:
	doxygen
	chmod ugo+rwx -R html
	chmod go-w -R html
	cp -p -r ./html/* ~/public_html/cs2301assig2


clean:
	rm -f *.o at at2 at3

