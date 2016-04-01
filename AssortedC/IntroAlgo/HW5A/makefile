all: openhash

TARGET = openhash
CFLAGS =-I.
INCLUDES = dlist.h hash.h
OBJECTS = dlist.o hash.o main.o 

CC = gcc -g  

%.o: %.c $(INCLUDES)
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm $(TARGET) *.o *~
