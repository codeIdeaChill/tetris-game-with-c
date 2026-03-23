#pragma once
#include "../include/raylib.h"
#define CellSize 30
#define row_offset 20
#define col_offset 10
extern int grid[row_offset][col_offset];
static Color Cellcolor[8] = {DARKGRAY, ORANGE, RED, GREEN, PURPLE, SKYBLUE, PINK, VIOLET};
void Grid();
void Draw();
void Print();
