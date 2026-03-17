#pragma once
#include "grid.h"
#define SIZE 4

typedef struct{
    int x,y;
}vector;
typedef struct{
    int shape[SIZE][SIZE];

}Shape;
typedef struct Blocks{
    int id;
    Shape shape[SIZE];
    vector position;
    Color color;
    void (*Move)(struct Blocks* self, int x, int y);
}Blocks;
typedef struct{
     Blocks blocks[7]; 
}Shapes;

void Move(Blocks* self, int x, int y);
void DrawTetromino(Blocks piece, int cellSize, int rot, int posY, int posX);
Shapes getallblocks();
Blocks GetRandomBlock();

