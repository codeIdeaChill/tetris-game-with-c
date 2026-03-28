# Compiler and Tools
CC = emcc
PROJECT_NAME = my_game
SRC_DIR = src
OBJ_DIR = obj
OUT_DIR = docs

# Find all .c files in your source directory
SRCS = $(wildcard $(SRC_DIR)/*.c)
# Define object files
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Compiler & Linker Flags
# -s ASYNCIFY: required for raylib's main loop in browser
# -s USE_GLFW=3: raylib uses GLFW for windowing
CFLAGS = -Wall -std=c99 -DPLATFORM_WEB -Os
LDFLAGS = -L./libs -lraylib -s USE_GLFW=3 -s ASYNCIFY

# Main Build Rule
all: $(OUT_DIR)/index.html

$(OUT_DIR)/index.html: $(OBJS)
	mkdir -p $(OUT_DIR)
	$(CC) -o $@ $(OBJS) $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -rf $(OBJ_DIR) $(OUT_DIR)

