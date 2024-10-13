CC = gcc

CFLAGS = -Wall -g

SRC = $(wildcard *.c)

EXE = $(patsubst %.c, ./build/%, $(SRC))

.PHONY: all
all: build_dir $(EXE)

./build/%: %.c
	$(CC) $(CFLAGS) -o $@ $<

build_dir:
	mkdir -p build

.PHONY: clean
clean:
	rm -rf ./build

