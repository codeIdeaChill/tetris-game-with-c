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


Posit Getcellposition(Blocks block, int rot);
bool IsBlockoutside(Blocks block, int rot);
bool IsCelloutside(int row, int col);
void replacegrid();

