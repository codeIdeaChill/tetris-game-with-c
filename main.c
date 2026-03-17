#include <stdio.h>
#include <raylib.h>
#include "grid.h"
#include "blocks.h"
#include "rotition.h"
#include "map.h"
#define WIDTH 500
#define HIEGHT 600
#define SellSize 30


int piecesY = 0;
float timer = 0.0f;
float movespeed = 0.8f;


int main(){
    InitWindow(WIDTH, HIEGHT, "tetris");

    SetTargetFPS(60);
    Grid();
    Print();
    Blocks block = GetRandomBlock();
    Posit test = Getcellposition(block, 0);
    for(int i =0;i <4;i++){
        printf("(%d ,%d) \n", test.b1[i].x, test.b1[i].y);
    }
    
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
            DrawTetromino(block , SellSize, rot, 0, 0);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
