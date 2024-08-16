CC		:=	gcc
CFLAGS	:=	-Wall	-g

CSOURCES 	:=	$(shell find . -name '*.c')
OBJECTS		:=	$(CSOURCES:.c=.o)

TARGET 		:= lab01

$(TARGET):	$(OBJECTS)
	$(CC) $(OBJECTS) -o $@

%.o: $.c
	$(CC) $(CFLAGS) -c $< -o $@

all:	$(TARGET)
	rm -f $(OBJECTS)

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY:	all	clean
