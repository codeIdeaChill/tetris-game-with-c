# Project Settings
PROJECT_NAME = my_game
SRC_DIR      = src
OBJ_DIR      = obj
BIN_DIR      = bin
INC_DIR      = include
INTERNAL_LIB = src/lib

# Source Discovery
SRCS = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(INTERNAL_LIB)/*.c)
OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir $(SRCS)))

# Compiler & Flags
CC     = gcc
CFLAGS = -Wall -std=c99 -Wno-missing-braces -Wno-unused-variable -I$(INC_DIR) -I$(INTERNAL_LIB)

# OS Detection & Static Linking Logic
ifeq ($(OS),Windows_NT)
    PLATFORM_OS = WINDOWS
    # Point directly to the static archive (.a)
    RAYLIB_LIB  = libs/windows/libraylib.a
    LDFLAGS     = $(RAYLIB_LIB) -lopengl32 -lgdi32 -lwinmm -lpthread -static-libgcc
    EXT         = .exe
else
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Linux)
        PLATFORM_OS = LINUX
        # Point directly to the static archive (.a)
        RAYLIB_LIB  = libs/linux/libraylib.a
        # System drivers must remain dynamic (-lGL, -lX11)
        LDFLAGS     = $(RAYLIB_LIB) -lGL -lm -lpthread -ldl -lrt -lX11
        EXT         =
    endif
endif

.PHONY: all clean

all: $(BIN_DIR)/$(PROJECT_NAME)$(EXT)

$(BIN_DIR)/$(PROJECT_NAME)$(EXT): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)
	@echo "Built successfully for $(PLATFORM_OS)"

# Rules to compile object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(INTERNAL_LIB)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
