CC = gcc -Wimplicit-function-declaration -Werror

all: warmup

printNum.o: printNum.c printNum.h
	$(CC) -g -c printNum.c

warmup.o: warmup.c
	$(CC) -g -c warmup.c

warmup: warmup.o printNum.o
	$(CC) -g -o warmup warmup.o printNum.o

clean: 
	rm warmup *.o *~
