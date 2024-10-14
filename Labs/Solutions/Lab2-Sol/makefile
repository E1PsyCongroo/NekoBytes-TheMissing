CC := gcc
CFLAGS := -Wall -Wextra -g -std=c11
TARGET := ex1 ex2 ex3 ex4 ex5 sudoku

all: $(TARGET)

$(TARGET): %:%.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	-rm -rf $(TARGET)

.PHONY: all clean
