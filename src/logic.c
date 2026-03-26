#include "lib/map.h"
#include "lib/rotition.h"

//get position of all cell in blocks for collition 
Posit Getcellposition(Blocks block, int rot){
    Posit cellpos;
    int i = 0;
    for(int row =0; row < 4; row++){
        for(int col = 0; col < 4; col++){
            if(i == 4)break;
            if(block.shape[rot].shape[row][col] == 1){
                cellpos.b1[i].x = (block.position.x ) + (col);
                cellpos.b1[i].y = (block.position.y ) + (row);
                i++;
            }
        }
    }
    return cellpos;
}


//check if cell is outside the grid
bool IsCelloutside(int row, int col){
    if(row >= 0 && row < cellRow  && col >= 0 && col < cellCol){
        return false;
    }
    return true;
}


//check if block is outside the grid 
bool IsBlockoutside(Blocks block, int rot){
    Posit tiles = Getcellposition(block, rot);
    for(int i =0;i < 4; i++){
        if(IsCelloutside((int)tiles.b1[i].y, (int)tiles.b1[i].x)){
            return true;
        }
    }
    return false;
}

//for new block if the current block is fit with abviose block
bool FitsBlock(Blocks test, int rot){
    Posit tiles = Getcellposition(test, rot);
    for(int i = 0;i < 4;i++){
        if(IscellEmpty(tiles.b1[i].x, tiles.b1[i].y)){
            return false;
        }
    }
    return true;

} 



