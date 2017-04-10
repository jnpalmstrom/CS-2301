all:  sorttest sorttest2

sorttest: sorttest.o sort.o timesort.o
	gcc -g sorttest.o sort.o timesort.o -o sorttest

sorttest.o: sorttest.c sort.h
	gcc -g -c --std=gnu89 sorttest.c

sorttest2: sorttest2.o sort2.o timesort2.o
	gcc -g sorttest2.o sort2.o timesort2.o -o sorttest2

sorttest2.o: sorttest2.c sort.h
	gcc -g -c --std=gnu89 sorttest2.c

sort.o: sort.c sort.h
	gcc -g -c --std=gnu89 sort.c

sort2.o: sort2.c sort2.h
	gcc -g -c --std=gnu89 sort2.c

timesort.o: timesort.c sort.h
	gcc -g -c --std=gnu89 timesort.c

timesort2.o: timesort2.c sort2.h
	gcc -g -c --std=gnu89 timesort2.c

clean:
	rm -f  *.o sorttest sorttest2

docs:
	doxygen
	chmod a+r html/*
	cp html/* ~/public_html/cs2301assig4
