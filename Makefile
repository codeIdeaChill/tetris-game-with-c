# 1. Project Settings
PROJECT_NAME = my_game
SRC_DIR      = src
OBJ_DIR      = obj
BIN_DIR      = bin

# Find all .c files in the source directory
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# 2. Platform Detection
# If you want to force an OS, run: make OS=Windows_NT
ifeq ($(OS),Windows_NT)
    PLATFORM_OS = WINDOWS
    CC = gcc
    # Assuming raylib is in a local folder or standard MinGW path
    LDFLAGS = -lraylib -lopengl32 -lgdi32 -lwinmm
    EXT = .exe
else
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Linux)
        PLATFORM_OS = LINUX
        CC = gcc
        # Linux requires these extra X11 libraries
        LDFLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
        EXT =
    endif
    ifeq ($(UNAME_S),Darwin)
        PLATFORM_OS = MACOS
        CC = clang
        # macOS uses Frameworks for graphics
        LDFLAGS = -lraylib -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL
        EXT =
    endif
endif

# 3. Compiler Flags
CFLAGS = -Wall -std=c99 -Wno-missing-braces -Iinclude

# 4. Build Rules
.PHONY: all clean

all: $(BIN_DIR)/$(PROJECT_NAME)$(EXT)

$(BIN_DIR)/$(PROJECT_NAME)$(EXT): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
