CC        := gcc
CFLAGS    := -Wall -Wpedantic -Werror -Og -g

WORK_DIR  := .
BUILD_DIR := $(WORK_DIR)/build
CSRCS     := $(shell find $(WORK_DIR)/src -name '*.c')
OBJS      := $(CSRCS:%.c=$(BUILD_DIR)/%.o)
TARGET    := echo

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $<

all: $(BUILD_DIR)/$(TARGET)

clean:
	rm -rf $(BUILD_DIR) $(TARGET)

.PHONY: all clean
