CC = gcc
CFLAGS = -O0 -Wall

TARGET = bubbleSort
SRC = test_sortv.c vector.c vector.h

all: $(TARGET)
clean:
	rm *.o
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)
