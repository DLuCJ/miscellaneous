all: ddcalculator

ddcalculator.o: ddcalculator.c ddcalculator.h
	gcc -g -c ddcalculator.c

stack.o: stack.c stack.h
	gcc -g -c stack.c

main.o: main.c
	gcc -g -c main.c

ddcalculator:  main.o stack.o ddcalculator.o
	gcc -g -o ddcalculator main.o stack.o ddcalculator.o

clean:
	rm ddcalculator *.o *~
