BUILD_DIR = ./build
CC := clang
LD := clang
CFLAGS := -Wall -Wextra -g -Og -fsanitize=address -fsanitize=undefined
LDFLAGS := $(CFLAGS) -lm
SRCS := $(wildcard *.c)
TARGETS := $(SRCS:%.c=$(BUILD_DIR)/%)

all: $(TARGETS)

$(BUILD_DIR)/%: %.o
	@mkdir -p $(dir $@)
	$(LD) -o $@ $< $(LDFLAGS)

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	-rm -rf $(BUILD_DIR)

.PHONY: clean all

