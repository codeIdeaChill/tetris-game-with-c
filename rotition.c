#include "rotition.h"
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

void MoveRight(Blocks* block, int rot){
    Move(block,1,0);
    if(IsBlockoutside(*block, rot)){
        Move(block,-1,0);
    }

}
void MoveLeft(Blocks* block, int rot){
    Move(block,-1,0);
    if(IsBlockoutside(*block, rot)){
        Move(block,1,0);
    }

}
void MoveDown(Blocks* block, int rot){
    Move(block,0,1);
    if(IsBlockoutside(*block, rot)){
        Move(block,0,-1);
    }

}

