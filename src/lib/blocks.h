#pragma once
#include "grid.h"
#define SIZE 4

//cordinate 
typedef struct{
    int x,y;
}vector;

//shapes matrix 4x4
typedef struct{
    int shape[SIZE][SIZE];

}Shape;
//blocks parameters
typedef struct Blocks{
    int id;
    Shape shape[SIZE];
    vector position;
    Color color;
    void (*Move)(struct Blocks* self, int x, int y);
}Blocks;

//struct for getallblocks function
typedef struct{
     Blocks blocks[7]; 
}Shapes;

void Move(Blocks* self, int x, int y);
void DrawTetromino(Blocks piece, int cellSize, int rot, int posY, int posX);
Shapes getallblocks();
Blocks GetRandomBlock();

