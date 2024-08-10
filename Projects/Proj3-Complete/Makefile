# 使用 gcc 作为编译器
CC = gcc
# 设置编译参数：使用 C11 标准，成调试信息
CFLAGS = -std=c11 -o0  -g
# 链接数学库
LIBS = -lm

# 主程序源文件列表
MAIN_SOURCES = perceptron.c math.c data_utils.c main.c
# 测试程序源文件列表
TEST_SOURCES = unity.c perceptron.c math.c data_utils.c test.c
# 包含的头文件
HEADERS = perceptron.h unity.h unity_internals.h

# 存放目标文件的目录
OBJDIR = obj

# 生成主程序的目标文件列表
MAIN_OBJECTS = $(addprefix $(OBJDIR)/, $(MAIN_SOURCES:.c=.o))
# 生成测试程序的目标文件列表
TEST_OBJECTS = $(addprefix $(OBJDIR)/, $(TEST_SOURCES:.c=.o))

# 默认目标：构建主程序和测试程序
all: main test

# 构建主程序
main: $(MAIN_OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

# 构建测试程序
test: $(TEST_OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

# 从源文件生成目标文件的规则
$(OBJDIR)/%.o: %.c $(HEADERS)
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# 清理目标，删除所有生成的文件
clean:
	rm -f main test
	rm -rf $(OBJDIR)
