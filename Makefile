include setup.mk

CC = gcc
PROFILE ?= DEBUG

CCFLAGS_DEBUG = -g -O0 -fno-builtin -DDEBUG
CCFLAGS_RELEASE = -O2

SRC_DIR := $(PROJ_DIR)/src
OBJ_DIR := $(PROJ_DIR)/obj
INC_DIR := $(PROJ_DIR)/include
BIN_DIR := $(PROJ_DIR)/bin
TEST_DIR := $(PROJ_DIR)/test

SRCS := $(wildcard $(SRC_DIR)/*.c)
DEPS := $(wildcard $(SRC_DIR)/*.h)
OBJS := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

CCFLAGS += $(CCFLAGS_$(PROFILE)) -I$(INC_DIR) -Wall -Wextra -Wformat -ansi -pedantic -std=c99 #-Werror
LDFLAGS += -lc -lcheck

BINS := $(BIN_DIR)/libstaticlac.a $(BIN_DIR)/liblac.so

# Create static and dynamic libraries
all: $(BINS)

# Copy libraries to /usr/lib
install: all
	cp -t /usr/lib/ ./bin/libstaticlac.a ./bin/liblac.so

# Remove object files and binaries
clean:
	rm -rf $(OBJ_DIR)/*.o $(BINS)

# Rebuild project
rebuild: clean all

# Create static library
$(BIN_DIR)/libstaticlac.a: $(OBJS)
	ar rcs ./bin/libstaticlac.a $^

# Create dynamic library
$(BIN_DIR)/liblac.so: $(SRCS) $(DEPS)
	$(CC) -o ./bin/liblac.so $^ -shared -fPIC $(CCFLAGS) $(LDFLAGS)
	#strip ./bin/liblac.so

# Create objects
$(OBJ_DIR)/%.o: $(SRCS)
	$(CC) $< -c -o $@ $(CCFLAGS)

# TODO: Modify test to include all tests
test: $(BIN_DIR)/test
	exec $(BIN_DIR)/test

$(BIN_DIR)/test: $(BIN_DIR)/liblac.so
	$(CC) -c $(TEST_DIR)/test.c -o $(OBJ_DIR)/test.o $(CCFLAGS)
	$(CC) $(OBJ_DIR)/test.o $^ -o $@ $(CCFLAGS) -llac $(LDFLAGS)

.PHONY: all install clean rebuild
