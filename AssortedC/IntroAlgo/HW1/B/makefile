
all: insertsort

isort.o: isort.c isort.h
	gcc -g -c isort.c

main.o: main.c
	gcc -g -c main.c

insertsort:  main.o isort.o
	gcc -g -o insertsort main.o isort.o

clean:
	rm insertsort *.o *~

