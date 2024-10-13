CC := gcc
CFLAGS := -Wall -Werror -Wpedantic -g -std=c11
TARGET := str_and_cyc

all: $(TARGET)

$(TARGET): %:%.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	-rm -rf $(TARGET)

.PHONY: all clean
