all: closehash

TARGET = closehash
CFLAGS =-I.
INCLUDES = hash.h
OBJECTS = hash.o main.o 

CC = gcc -g  

%.o: %.c $(INCLUDES)
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm $(TARGET) *.o *~
