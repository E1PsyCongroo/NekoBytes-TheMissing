#
# Students' Makefile for the Malloc Lab
#
TEAM = bovik
VERSION = 1
HANDINDIR = /afs/cs.cmu.edu/academic/class/15213-f01/malloclab/handin

CC = gcc
CFLAGS = -Wall -O2
LDFLAGS = -lcriterion  # 添加 Criterion 库链接选项

OBJS = mdriver.o mm.o memlib.o fsecs.o fcyc.o clock.o ftimer.o  # 不包括 test.o
TEST_OBJS = test.o  # 单独定义 test.o 的目标

mdriver: $(OBJS)
	$(CC) $(CFLAGS) -o mdriver $(OBJS) $(LDFLAGS)  # 链接时包含 Criterion 库

test: $(TEST_OBJS)
	$(CC) $(CFLAGS) -o test $(TEST_OBJS) $(LDFLAGS)  # 生成 test 可执行文件

# 目标文件规则
mdriver.o: mdriver.c fsecs.h fcyc.h clock.h memlib.h config.h mm.h
memlib.o: memlib.c memlib.h
mm.o: mm.c mm.h memlib.h
fsecs.o: fsecs.c fsecs.h config.h
fcyc.o: fcyc.c fcyc.h
ftimer.o: ftimer.c ftimer.h config.h
clock.o: clock.c clock.h
test.o: test.c  # 添加 test.o 的规则

handin:
	cp mm.c $(HANDINDIR)/$(TEAM)-$(VERSION)-mm.c

clean:
	rm -f *~ *.o mdriver test  # 清理 test 可执行文件