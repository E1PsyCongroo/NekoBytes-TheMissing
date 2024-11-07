CC = gcc

CSRC += $(abspath $(shell find ./src -name "*.c"))

INC_FILES += $(abspath $(shell find ./include -name "*.h"))
INCPATH += $(abspath ./include)

CFLAGS += $(addprefix -I, $(INCPATH))
CFLAGS += -Wall -Werror

BUILD_DIR = $(abspath ./build)
TARGET = $(BUILD_DIR)/zuma

$(TARGET): $(CSRC) $(INC_FILES)
	mkdir -p $(BUILD_DIR)
	$(CC) $(CSRC) $(CFLAGS) -o $(TARGET)

run: $(TARGET)
	$(TARGET)

clean:
	rm -rf $(BUILD_DIR)
