CC := gcc
CFLAGS := -Wall -Wextra -g -std=c11
TARGET := ex1_ptr ex2_arrays ex3_ptr_ari ex4_string ex5_ptr_and_fun

all: $(TARGET)

$(TARGET): %:%.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	-rm -rf $(TARGET)

.PHONY: all clean
