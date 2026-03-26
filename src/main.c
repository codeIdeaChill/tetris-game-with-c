#include <stdio.h>
#include <stdbool.h>
#include "../include/raylib.h"
#include "lib/grid.h"
#include "lib/blocks.h"
#include "lib/rotition.h"
#include "lib/map.h"
#define WIDTH 500
#define HIEGHT 600
#define SellSize 30


double lastUpdateTime = 0;
bool EventTriggered(double interval){
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main(){
    //initialse window
    InitWindow(WIDTH, HIEGHT, "tetris");

    SetTargetFPS(60);
    Grid(); // initial grid as 0
    Blocks currentBlock = GetRandomBlock();
    //Blocks nextBlock = GetRandomBlock();
    
    //game loop 
    while(!WindowShouldClose()){

        if(IsKeyPressed(KEY_UP)){
            rot = rotState(currentBlock, rot);
        }
        Posit test = Getcellposition(currentBlock,rot);
        for(int i = 0; i<4;i++){
            if(test.b1[i].x < 0){
                Move(&currentBlock,1,0);
            }else if(test.b1[i].x >= 10){
                Move(&currentBlock, -1,0);
            }
        }
        if(EventTriggered(0.3) && FitsBlock(currentBlock,rot)){
            MoveDown(&currentBlock,rot);
        }
        handleEvent(&currentBlock, rot);
        BeginDrawing();
            ClearBackground(DARKBLUE);
            Draw();
            DrawTetromino(currentBlock , CellSize, rot, 0, 0);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
