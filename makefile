main: main.c dqlib.h

	gcc -g -fsanitize=address main.c -I.


#dqlib.o: main.c dqlib.h 
#	gcc -c main.c
#
#dqlib.a: dqlib.o
#	ar cr dqlib.a dqlib.o
#
#clean:
#	rm dqlib.o
