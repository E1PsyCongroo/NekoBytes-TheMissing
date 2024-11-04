CC = gcc
CFLAGS = -Wall -g

OBJS = mdriver.o mm.o memlib.o fsecs.o fcyc.o clock.o ftimer.o mtest.o  

all: mdriver mtest

mdriver: $(OBJS)
	$(CC) $(CFLAGS) -o mdriver mdriver.o mm.o memlib.o fsecs.o fcyc.o clock.o ftimer.o

mtest: mtest.o mm.o memlib.o fcyc.o clock.o ftimer.o
	$(CC) $(CFLAGS) -o mtest mtest.o mm.o memlib.o fcyc.o clock.o ftimer.o

# 目标文件规则
mdriver.o: mdriver.c fsecs.h fcyc.h clock.h memlib.h config.h mm.h
mtest.o: mtest.c fsecs.h fcyc.h clock.h memlib.h config.h mm.h
memlib.o: memlib.c memlib.h
mm.o: mm.c mm.h memlib.h
fsecs.o: fsecs.c fsecs.h config.h
fcyc.o: fcyc.c fcyc.h
ftimer.o: ftimer.c ftimer.h config.h
clock.o: clock.c clock.h

clean:
	rm -f *~ *.o mdriver mtest