CC := gcc
CFLAGS := -Wall -Werror -g
TARGET := 2048 bubble_vs_merge high-precision_mul

all: $(TARGET)

$(TARGET): %:%.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	-rm -rf $(TARGET)

.PHONY: all clean
