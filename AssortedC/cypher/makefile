all: cypher

TARGET = cypher
CFLAGS =-I.
INCLUDES = cypher.h
OBJECTS = cypher.o

CC = clang 
COPTS = -g -Wall

test: $(TARGET)
	./test.sh

%.o: %.c $(INCLUDES) 
	$(CC) $(COPTS) -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJECTS)
	$(CC) $(COPTS) -o $@ $^ $(CFLAGS)

archive:
	tar czvf dlucypher.tar.gz README makefile cypher.c cypher.h test.sh

.PHONY:
	clean

clean:
	rm -rf *.o *~ *.dSYM *.tar.gz

clobber:
	rm -rf *.o *~ *.dSYM $(TARGET) *.tar.gz
