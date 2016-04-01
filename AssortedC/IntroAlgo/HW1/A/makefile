all: stack

stack.o: stack.c stack.h
	gcc -g -c stack.c

main.o: main.c 
	gcc -g -c main.c

stack: 	main.o stack.o
	gcc -g -o stack main.o stack.o

clean: 
	rm stack *.o *~ 