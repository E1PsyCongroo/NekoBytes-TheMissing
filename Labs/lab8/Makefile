# 使用 gcc 作为编译器
CC = gcc
# 设置编译参数：使用 C11 标准，生成调试信息
CFLAGS = -std=c11 -g

# 主程序源文件列表
MAIN_SOURCES = main.c data_utils.c linear_regression.c multiple_regression.c
# 测试程序源文件列表
TEST_SOURCES = data_utils.c linear_regression.c test.c
# 包含的头文件
HEADERS = regression.h

# 存放目标文件的目录
OBJDIR = obj

MAIN_OBJECTS = $(addprefix $(OBJDIR)/, $(notdir $(MAIN_SOURCES:.c=.o)))
TEST_OBJECTS = $(addprefix $(OBJDIR)/, $(notdir $(TEST_SOURCES:.c=.o)))

all: main test

# 构建主程序
main: $(MAIN_OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

# 构建测试程序
test: $(TEST_OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

# 从源文件生成目标文件的规则
$(OBJDIR)/%.o: %.c $(HEADERS)
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# 清理目标，删除所有生成的文件
clean:
	rm -f main test
	rm -rf $(OBJDIR)
