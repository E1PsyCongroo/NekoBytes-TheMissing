**因为在原makefile里直接修改内容会导致无法通过check_hashes.py的检验，因此在这里独立出一个md文件来提供注释版本**

```Makefile
# 设置编译器为gcc
CC = gcc

# 设置编译标志：启用所有警告，忽略未使用函数警告，启用类型转换警告，使用C99标准，启用调试信息
CFLAGS = -Wall -Wno-unused-function -Wconversion -std=c99 -g

# 链接标志（当前为空）
LDFLAGS =

# 定义snake可执行文件的依赖文件
SNAKE_DEPS = src/snake.o src/snake_utils.o src/state.o

# 定义interactive-snake可执行文件的依赖文件
INTERACTIVE_DEPS = src/interactive_snake.o src/snake_utils.o src/state.o

# 定义unit-tests可执行文件的依赖文件
UNIT_TESTS_DEPS = src/snake_utils.o src/unit_tests.o src/asserts.o

# 定义custom-tests可执行文件的依赖文件
CUSTOM_TESTS_DEPS = src/snake_utils.o src/custom_tests.o src/asserts.o

# 短测试文件名列表
SHORTER_TESTS = 01-simple 02-direction 03-tail 04-food 05-wall 06-small 07-medium 08-multisnake 09-everything 10-filled 11-manyclose 12-corner 13-sus 14-orochi 15-hydra

# 长测试文件名列表
LONGER_TESTS = 16-huge 17-wide 18-tall 19-101-127 20-long-line 21-bigL

# 定义颜色变量，初始为空
COLOR_GREEN =
COLOR_RESET =

# 如果NO_COLOR未定义并且终端类型包含xterm，则设置颜色
ifeq (,${NO_COLOR})
	ifneq (,$(findstring xterm,${TERM}))
		override COLOR_GREEN := $(shell tput setaf 2)
		override COLOR_RESET := $(shell tput sgr0)
	endif
endif

# 帮助命令，显示可用命令和说明
help:
	@echo Usage:
	@echo make run-unit-tests: Compiles and runs unit tests.
	@echo make run-custom-tests: Compiles and runs custom tests.
	@echo make debug-unit-tests: Compiles unit tests and starts the debugger.
	@echo make debug-custom-tests: Compiles custom tests and starts the debugger.
	@echo make valgrind-test-free-state: Runs the test_free_state unit test under Valgrind.
	@echo make run-nonexistent-input-file-test: Checks that your program returns -1 on a nonexistent input file.
	@echo make run-integration-tests: Compiles and runs integration tests.
	@echo make snake: Compiles the snake executable.
	@echo make unit-tests: Compiles the unit tests.
	@echo make custom-tests: Compiles the custom tests.
	@echo make interactive-snake: Compiles the interactive snake executable.
	@echo make clean: Removes executables and output files.

# 定义伪目标all，编译所有目标
.PHONY: all
all: interactive-snake snake unit-tests custom-tests

# 编译snake可执行文件
snake: $(SNAKE_DEPS)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

# 编译interactive-snake可执行文件，使用pthread
interactive-snake: $(INTERACTIVE_DEPS)
	$(CC) -o $@ $^ -pthread $(CFLAGS) $(LDFLAGS)

# 编译unit-tests可执行文件
unit-tests: $(UNIT_TESTS_DEPS)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

# 编译custom-tests可执行文件
custom-tests: $(CUSTOM_TESTS_DEPS)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

# 编译通用规则，生成.o文件
%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

# 编译unit_tests.o文件的特殊规则，包含依赖文件
src/unit_tests.o: src/unit_tests.c src/state.c src/asserts.c
	$(CC) -c -o $@ $< $(CFLAGS)

# 编译custom-tests.o文件的特殊规则，包含依赖文件
src/custom-tests.o: src/custom_tests.c src/state.c src/asserts.c
	$(CC) -c -o $@ $< $(CFLAGS)

# 伪目标check-hashes，检查哈希值
.PHONY: check-hashes
check-hashes:
	@bash tools/run_python.sh tools/check_hashes.py

# 伪目标clean，删除可执行文件和输出文件
.PHONY: clean
clean:
	rm -f interactive-snake snake unit-tests custom-tests unit-test-*.snk *.exe *.o src/*.o tests/*-out.snk

# 伪目标debug-unit-tests，使用cgdb调试unit-tests
.PHONY: debug-unit-tests
debug-unit-tests: unit-tests check-hashes
	cgdb ./unit-tests

# 伪目标run-unit-tests，运行unit-tests
.PHONY: run-unit-tests
run-unit-tests: unit-tests check-hashes
	./unit-tests

# 伪目标debug-custom-tests，使用cgdb调试custom-tests
.PHONY: debug-custom-tests
debug-custom-tests: custom-tests
	cgdb ./custom-tests

# 伪目标run-custom-tests，运行custom-tests
.PHONY: run-custom-tests
run-custom-tests: custom-tests
	./custom-tests

# 伪目标valgrind-test-free-state，使用Valgrind运行unit-tests的test_free_state
.PHONY: valgrind-test-free-state
valgrind-test-free-state: unit-tests
	valgrind --leak-check=full --track-origins=yes ./unit-tests -m

# 伪目标run-integration-tests，运行集成测试
.PHONY: run-integration-tests
run-integration-tests: $(SHORTER_TESTS) $(LONGER_TESTS) run-nonexistent-input-file-test

# 伪目标run-nonexistent-input-file-test，测试不存在的输入文件
.PHONY: run-nonexistent-input-file-test
run-nonexistent-input-file-test: snake
	@bash tools/test_nonexistent_input_file.sh

# 伪目标SHORTER_TESTS，运行短测试
.PHONY: $(SHORTER_TESTS)
$(SHORTER_TESTS): snake check-hashes
	@sed 's/\r$$//g' "tests/$(@F)-in.snk" > "tests/.$(@F)-in.snk.tmp"
	@mv "tests/.$(@F)-in.snk.tmp" "tests/$(@F)-in.snk"
	@sed 's/\r$$//g' "tests/$(@F)-ref.snk" > "tests/.$(@F)-ref.snk.tmp"
	@mv "tests/.$(@F)-ref.snk.tmp" "tests/$(@F)-ref.snk"
	@rm -f "tests/$(@F)-out.snk"
	./snake -i "tests/$(@F)-in.snk" -o "tests/$(@F)-out.snk"
	diff "tests/$(@F)-ref.snk" "tests/$(@F)-out.snk"
	@echo "${COLOR_GREEN}Passed $(@F)${COLOR_RESET}"

# 伪目标LONGER_TESTS，运行长测试
.PHONY: $(LONGER_TESTS)
$(LONGER_TESTS): snake check-hashes
	@sed 's/\r$$//g' "tests/$(@F)-in.snk" > "tests/.$(@F)-in.snk.tmp"
	@mv "tests/.$(@F)-in.snk.tmp" "tests/$(@F)-in.snk"
	@sed 's/\r$$//g' "tests/$(@F)-ref.snk" > "tests/.$(@F)-ref.snk.tmp"
	@mv "tests/.$(@F)-ref.snk.tmp" "tests/$(@F)-ref.snk"
	@rm -f "tests/$(@F)-out.snk"
	./snake -i "tests/$(@F)-in.snk" -o "tests/$(@F)-out.snk"
	diff -q "tests/$(@F)-ref.snk" "tests/$(@F)-out.snk"
	@echo "${COLOR_GREEN}Passed $(@F)${COLOR_RESET}"


```