BUILD_DIR = ./build
CC := gcc
CFLAGS := -Wall -Wextra -g -std=c11
SRCS := $(wildcard *.c)
TARGETS := $(SRCS:%.c=$(BUILD_DIR)/%)

all: $(TARGETS)

$(BUILD_DIR)/%: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	-rm -rf $(BUILD_DIR)

.PHONY: clean all

