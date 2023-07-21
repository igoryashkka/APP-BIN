CC = gcc
CFLAGS = -Wall -Wextra -O1 -g

SRCS = main.c lib.c
HDRS = main.h lib.h
OBJS = $(SRCS:.c=.o)
TARGET = run

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

test: unit_test.o lib.o 
	$(CC) $(CFLAGS) -o test unit_test.o lib.o


%.o: %.c $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

debug: CFLAGS += -DDEBUG
debug: all

.PHONY: debug