CC := gcc
CFLAGS := -Wall -Wextra -Werror -g -std=c11
TARGET := stack

all: $(TARGET)

$(TARGET): %:%.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	-rm -rf $(TARGET)

.PHONY: all clean
