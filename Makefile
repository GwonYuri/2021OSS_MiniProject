CC = gcc
CFLAGS = -W -Wall
TARGET = fruit
DTARGET = fruit_debug
OBJECTS = main.c manager.o product.o
all : $(TARGET)
$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

$(DTARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -DDEBUG -o $@ $^
clean:
	rm -f *.o $(TARGET) $(DTARGET) 
