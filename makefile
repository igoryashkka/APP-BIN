CC = gcc
CFLAGS = -Wall -Wextra -O1 -g
SRC_DIR = src
OBJ_DIR = obj

SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/lib.c
TEST_SRCS = $(SRC_DIR)/unit_test.c $(SRC_DIR)/lib.c
HDRS = $(SRC_DIR)/main.h $(SRC_DIR)/lib.h
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
TEST_OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(TEST_SRCS))
TARGET = $(OBJ_DIR)/run
TEST_TARGET = $(OBJ_DIR)/test

.PHONY: all clean

all: $(TARGET)

$(OBJ_DIR)/run: $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(TEST_TARGET): $(TEST_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TEST_OBJS) $(TARGET) $(TEST_TARGET)

debug: CFLAGS += -DDEBUG
debug: all

.PHONY: debug
