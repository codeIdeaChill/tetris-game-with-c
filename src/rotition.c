#include "lib/rotition.h"

//for rotition 

int rotState(Blocks currentBlock, int rot){
    rot++;
    if(rot>3)rot=0;
    return rot;
}


//handle event mave the block right or left
void handleEvent(Blocks* block, int rot){
    int event = GetKeyPressed();
    if(gameOver && event == KEY_R){
        rest();
        gameOver = false;
        score = 0;
    }
    switch(event){
        case KEY_RIGHT:
            MoveRight(block,rot);       
            break;
        case KEY_LEFT:
            MoveLeft(block,rot);       
            break;
        case KEY_DOWN:
            MoveDown(block,rot);       
            break;
        case KEY_R:
              rest();
              score = 0;
              gameOver = false;
              break;

    }
}

// right function
void MoveRight(Blocks* block, int rot){
    if(!gameOver){
        Move(block,1,0);
        if(IsBlockoutside(*block, rot) || !FitsBlock(currentBlock,rot)){
            Move(block,-1,0);
        }

    }

}
//left function
void MoveLeft(Blocks* block, int rot){
    if(!gameOver){
        Move(block,-1,0);
        if(IsBlockoutside(*block, rot) || !FitsBlock(currentBlock,rot)){
            Move(block,1,0);
        }

    }

}
//lock function if block touch the bottom
void LockBlock(Blocks block, int rot){
    Posit tiles = Getcellposition(block, rot);
    for(int i = 0; i<4; i++){
        grid[tiles.b1[i].y][tiles.b1[i].x] = block.id;
    }
    
}
void DrawNextBlock(Blocks block){
    DrawTetromino(block , CellSize, rot, 0, 0);
}
void newBlock(Blocks* block,int rot){
    nextBlock = GetRandomBlock();
    *block = nextBlock;
    block->position.y = 0;
}

//move down function
void MoveDown(Blocks* block, int rot){
    if(!gameOver){
        Move(block,0,1);
        if(IsBlockoutside(*block, rot) || !FitsBlock(*block,rot)){
            Move(block,0,-1);
            LockBlock(*block, rot);
            newBlock(block, rot);
            if(!FitsBlock(*block, rot)){
                gameOver = true;
            }
        }

    }

}


