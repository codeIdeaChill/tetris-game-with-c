#pragma once 
#include "grid.h"
#include "blocks.h"
#include <stdbool.h>

#define cellRow 20
#define cellCol 10


//struct of position of cells
typedef struct{
    vector b1[4];
}Posit;
static bool gameOver = false;
static int score = 0;
static Blocks currentBlock;
static Blocks nextBlock;
Posit Getcellposition(Blocks block, int rot);
bool IsBlockoutside(Blocks block, int rot);
bool IsCelloutside(int row, int col);
bool FitsBlock(Blocks test, int rot);
void GameInfo(Font font);
void rest();
