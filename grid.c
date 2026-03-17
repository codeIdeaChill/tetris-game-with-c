#include <stdio.h>
#include "grid.h"
int grid[20][10];
void Grid(){
    for (int i =0; i < 20; i++){
        for (int j =0; j < 10; j++){
            grid[i][j] = 0;
        }
    }

}
void Print(){

    for(int i=0; i< 20; i++){
          for(int j=0; j<10; j++){
              printf("%d ", grid[i][j]);
          }
          printf("\n");
     } 
}
void Draw(){
    for(int row = 0; row < 10; row++){
        for(int col = 0; col < 20; col++){
            int cellvalue = grid[col][row];
            DrawRectangle((row * 30) + 1 ,(col * 30) + 1 , 29, 29, Cellcolor[cellvalue]);
        }
    }
}

