all: duel

dlist.o: dlist.c dlist.h
	gcc -g -c dlist.c
util.o: util.c util.h
	gcc -g -c util.c
main.o: main.c
	gcc -g -c main.c

duel:  main.o dlist.o util.o
	gcc -g -o duel main.o dlist.o util.o

clean:
	rm duel *.o *~
