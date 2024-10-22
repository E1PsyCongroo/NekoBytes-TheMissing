# 指定编译器
CC = gcc

# 编译选项
CFLAGS = -fdiagnostics-color=always -g

# 源文件和目标文件
SRC = matrix_multiply.c matrix_functions.c
OBJ = $(SRC:.c=.o)

# 可执行文件名称
TARGET = matrix_multiply

# 默认目标
all: $(TARGET)

# 链接目标，设置栈大小为 256MB（268435456 字节）
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $@ -Wl,-z,stack-size=268435456

# 编译每个源文件为目标文件
%.o: %.c matrix_functions.h
	$(CC) $(CFLAGS) -c $<

# 清理目标
clean:
	rm -f $(OBJ) $(TARGET)

# 伪目标
.PHONY: all clean clear

# 添加 clear 目标，指向 clean
clear: clean