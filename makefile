CC = gcc
CFLAGS = -Wall -Wextra -O3 -ffast-math -g

SRCS = main.c lib.c
HDRS = main.h lib.h
OBJS = $(SRCS:.c=.o)
TARGET = run

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
