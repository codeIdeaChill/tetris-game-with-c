#include "rotition.h"

int rotition(){
    static int rot = 0;
    if(rot <0 || rot > 3){
        rot = 0;
    }else{
        if(IsKeyPressed(KEY_UP))rot++;
    }
    return rot;
}
void handleEvent(Blocks* block){
    int event = GetKeyPressed();
    switch(event){
        case KEY_RIGHT:
            Move(block,1,0);
            break;
        case KEY_LEFT:
            Move(block,-1,0);
            break;
        case KEY_DOWN:
            Move(block,0,1);
            break;

    }
            

}

