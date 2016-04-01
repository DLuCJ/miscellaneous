all: bsearch

TARGET = bsearch
CFLAGS =-I.
INCLUDES = tree.h
OBJECTS = tree.o main.o 

CC = gcc -g  

%.o: %.c $(INCLUDES)
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm $(TARGET) *.o *~
