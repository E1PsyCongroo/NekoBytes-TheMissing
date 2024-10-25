# 定义编译器
CC = gcc

# 定义编译选项
CFLAGS = -MMD -Wall -Werror -g

# 定义源文件和目标文件
BUILD_DIR = ./build
SRC_DIR = ./src
SRCS = $(shell find $(SRC_DIR) -type f -name "*.c")
OBJS = $(patsubst %.c, $(BUILD_DIR)/%.o, $(notdir $(SRCS)))
DEPS = $(OBJS:.o:.d)

-include $(DEPS)

# 定义可执行文件名称
TARGET = $(BUILD_DIR)/judge

# 默认目标
all: $(TARGET)

# 运行程序
run: $(TARGET)
	@$(TARGET)

# 链接目标文件生成可执行文件
$(TARGET): $(OBJS)
	@echo + LD $@
	@$(CC) $(CFLAGS) -o $@ $^

# 编译源文件为目标文件
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@echo + CC $<
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

# 清理生成的文件
clean:
	-rm -rf $(BUILD_DIR)

# 伪目标
.PHONY: all clean run
