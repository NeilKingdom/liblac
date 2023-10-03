CC = gcc
PROFILE ?= DEBUG

CCFLAGS_DEBUG = -g -O0 -fno-builtin -DDEBUG
CCFLAGS_RELEASE = -O2

SRC_DIR := src
OBJ_DIR := obj
INC_DIR := include
BIN_DIR := bin
TEST_DIR := test

SRCS := $(wildcard $(SRC_DIR)/*.c)
DEPS := $(wildcard $(SRC_DIR)/*.h)
OBJS := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# WARNING: Don't use -ansi flag, as this will discard the math.h cos/sin function definitions
CCFLAGS += $(CCFLAGS_$(PROFILE)) -I$(INC_DIR) -Wall -Wextra -Wformat -std=c99 #-Werror
LDFLAGS += -lc -lm -lcheck

BINS := $(BIN_DIR)/liblac.a $(BIN_DIR)/liblac.so

# Create static and dynamic libraries
all: $(BINS)

# Copy libraries to /usr/lib
install: all
	cp $(BINS) /usr/lib/

# Remove object files and binaries
clean:
	rm -rf $(OBJ_DIR)/*.o $(BIN_DIR)/*

# Rebuild project
rebuild: clean all

# Create static library
$(BIN_DIR)/liblac.a: $(OBJS)
	ar rcs $@ $^

# Create dynamic library
$(BIN_DIR)/liblac.so: $(SRCS) $(DEPS)
	$(CC) -o $@ $(SRCS) $(DEPS) -shared -fPIC $(CCFLAGS) $(LDFLAGS)
	#strip ./bin/liblac.so

# Create objects
$(OBJ_DIR)/%.o: $(SRCS)
	$(CC) $< -c -o $@ $(CCFLAGS)

# TODO: Modify test to include all tests
test: install
	$(CC) $(TEST_DIR)/test.c -o $(BIN_DIR)/test $(CCFLAGS) $(LDFLAGS) -llac

.PHONY: all install clean rebuild test
