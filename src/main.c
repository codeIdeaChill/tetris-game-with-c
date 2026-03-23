#include <stdio.h>
#include "../include/raylib.h"
#include "lib/grid.h"
#include "lib/blocks.h"
#include "lib/rotition.h"
#include "lib/map.h"
#define WIDTH 500
#define HIEGHT 600
#define SellSize 30


int piecesY = 0;
float timer = 0.0f;
float movespeed = 0.8f;


int main(){
    //initialse window
    InitWindow(WIDTH, HIEGHT, "tetris");

    SetTargetFPS(60);
    Grid(); // initial grid as 0
    Blocks block = GetRandomBlock();
    Posit test = Getcellposition(block, 0);
    
    while(!WindowShouldClose()){

        if(IsBlockoutside(block, rot)){
            rot = Undorotition(rot);
        }else{
            rot = rotition(rot);
        }
        handleEvent(&block, rot);
        timer += GetFrameTime();
        if(timer >= movespeed){
            piecesY += 1;
            timer = 0.0f;
        }
        BeginDrawing();
            ClearBackground(DARKBLUE);
            Draw();
            DrawTetromino(block , CellSize, rot, 0, 0);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
