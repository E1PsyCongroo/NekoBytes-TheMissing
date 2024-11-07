CC = gcc

BUILD_DIR = $(abspath ./build)
TARGET = $(BUILD_DIR)/zuma

# 搜索源文件和头文件
CSRC += $(abspath $(shell find ./src -name "*.c"))
OBJFILES = $(patsubst $(abspath ./src)/%, $(BUILD_DIR)/%, $(CSRC:.c=.o))
DEPS = $(OBJFILES:.o=.d)

INC_FILES += $(abspath $(shell find ./include -name "*.h"))
INCPATH += $(abspath ./include)

CFLAGS += $(addprefix -I, $(INCPATH))
CFLAGS += -Wall -Werror -MMD

# 生成 .o 文件时，将输出放入 BUILD_DIR 中
$(BUILD_DIR)/%.o: ./src/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

-include $(DEPS)

# 链接最终的目标文件
$(TARGET): $(OBJFILES)
	mkdir -p $(BUILD_DIR)
	$(CC) $(OBJFILES) $(CFLAGS) -o $(TARGET)

# 运行目标
run: $(TARGET)
	$(TARGET)

# 清理目标
clean:
	rm -rf $(BUILD_DIR)