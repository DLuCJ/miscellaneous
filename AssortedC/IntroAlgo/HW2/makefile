all: calculator

calculator.o: calculator.c calculator.h
	gcc -g -c calculator.c

stack.o: stack.c stack.h
	gcc -g -c stack.c

main.o: main.c
	gcc -g -c main.c

calculator:  main.o stack.o calculator.o
	gcc -g -o calculator main.o stack.o calculator.o

clean:
	rm calculator *.o *~
