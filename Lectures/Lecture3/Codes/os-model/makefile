CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11
TARGET=main

$(TARGET): main.c os.c os.h
	$(CC) -o $(TARGET) main.c os.c $(CFLAGS)

all: $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
