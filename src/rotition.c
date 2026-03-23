#include "lib/rotition.h"

//for rotition 
int rotition(int rot){
    if(rot <0 || rot > 3){
        rot = 0;
    }else{
        if(IsKeyPressed(KEY_UP))rot++;
    }
    return rot;
}
int Undorotition(int rot){
    
    if(rot <0 || rot > 3){
        rot = 0;
    }else{
        if(IsKeyPressed(KEY_UP)){rot--;}
    }
    return rot;
}


//handle event mave the block right or left
void handleEvent(Blocks* block, int rot){
    int event = GetKeyPressed();
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

    }
}

// right function
void MoveRight(Blocks* block, int rot){
    Move(block,1,0);
    if(IsBlockoutside(*block, rot)){
        Move(block,-1,0);
    }

}
//left function
void MoveLeft(Blocks* block, int rot){
    Move(block,-1,0);
    if(IsBlockoutside(*block, rot)){
        Move(block,1,0);
    }

}
//lock function if block touch the bottom
void LockBlock(Blocks block, int rot){
    Blocks currentBlock = block;
    Blocks nextBlock = GetRandomBlock();
    Posit tiles = Getcellposition(currentBlock, rot);
    for(int i = 0; i<4; i++){
        grid[tiles.b1[i].y][tiles.b1[i].x] = block.id;
    }
    currentBlock = nextBlock;
}


//move down function
void MoveDown(Blocks* block, int rot){
    Move(block,0,1);
    if(IsBlockoutside(*block, rot)){
        Move(block,0,-1);
        LockBlock(*block, rot);
    }

}

