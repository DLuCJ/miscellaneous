all: heapsort

TARGET = heapsort
CFLAGS =-I.
INCLUDES = heap.h
OBJECTS = heap.o main.o 

CC = gcc -g  

%.o: %.c $(INCLUDES)
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm $(TARGET) *.o *~
