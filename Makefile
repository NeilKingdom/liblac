CC = gcc
PROFILE ?= RELEASE

CCFLAGS_DEBUG = -ggdb -O0 -fno-builtin -DDEBUG
CCFLAGS_RELEASE = -Ofast

SRC_DIR := src
OBJ_DIR := obj
INC_DIR := include
BIN_DIR := bin
TEST_DIR := test

TGT_INC_DIR := /usr/include/
TGT_BIN_DIR := /usr/lib/

SRCS := $(wildcard $(SRC_DIR)/*.c)
DEPS := $(wildcard $(INC_DIR)/*.h)
OBJS := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

CCFLAGS += $(CCFLAGS_$(PROFILE)) -I$(INC_DIR) -std=c99 -Wall -Wextra -Wformat -Werror
LDFLAGS += -lc -lm -lcheck

BINS := $(BIN_DIR)/liblac.a $(BIN_DIR)/liblac.so

# Create static and dynamic libraries
all: prebuild $(BINS)

# Copy libraries to /usr/lib
install: all
	cp $(BINS) $(TGT_BIN_DIR)
	cp $(INC_DIR)/*.h $(TGT_INC_DIR)

# Pre-build actions
prebuild:
	mkdir -p $(OBJ_DIR)
	mkdir -p $(BIN_DIR)

# Remove object files and binaries
clean:
	rm -f $(OBJ_DIR)/*.o $(BIN_DIR)/*

# Rebuild project
rebuild: clean all

# Create static library
$(BIN_DIR)/liblac.a: $(OBJS)
	ar rcs $@ $^

# Create dynamic library
$(BIN_DIR)/liblac.so: $(SRCS) $(DEPS)
	$(CC) -o $@ $(SRCS) $(DEPS) -shared -fPIC $(CCFLAGS) $(LDFLAGS)
ifeq ($(PROFILE), RELEASE)
	strip ./bin/liblac.so
endif

# Create objects
$(OBJ_DIR)/%.o: $(SRCS)
	$(CC) $< -c -o $@ $(CCFLAGS)

# TODO: Modify test to include all tests
test: install
	$(CC) $(TEST_DIR)/test.c -o $(BIN_DIR)/test $(CCFLAGS) $(LDFLAGS) -llac

.PHONY: all install clean rebuild test
