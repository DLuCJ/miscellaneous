all: card

TARGET = card
OBJECTS = card.o 

#compiler type
CC = g++

%.o: %.c 
	$(CC) -o $@ $< 

$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^ 

clean:
	rm $(TARGET) *.o *.~ *.ppm

