CC := gcc
CFLAGS := -Wall -Werror -g
TARGET := type swap intvector linkedlist

all: $(TARGET)

$(TARGET): %:%.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	-rm -rf $(TARGET)

.PHONY: all clean
