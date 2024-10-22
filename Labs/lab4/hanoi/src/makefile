# 定义编译器
CC = gcc

# 定义编译选项
CFLAGS = -Wall -g

# 定义源文件和目标文件
SRCS = hanoi.c judge.c tower.c
OBJS = $(SRCS:.c=.o)

# 定义可执行文件名称
TARGET = judge

# 默认目标
all: $(TARGET)

# 链接目标文件生成可执行文件
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# 编译源文件为目标文件
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# 清理生成的文件
clean:
	rm -f $(OBJS) $(TARGET)

# 伪目标
.PHONY: all clean