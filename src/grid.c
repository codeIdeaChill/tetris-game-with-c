#include <stdio.h>
#include "lib/grid.h"
//initial grid as 20 rows and 10 columns
int grid[20][10];
void Grid(){
    for (int i =0; i < 20; i++){
        for (int j =0; j < 10; j++){
            grid[i][j] = 0;
        }
    }

}
//function for print grid if we want to
void Print(){
    for(int i=0; i< 20; i++){
          for(int j=0; j<10; j++){
              printf("%d ", grid[i][j]);
          }
          printf("\n");
     } 
}
//draw rectangle for each cell of grid according to the value of it
void Draw(){
    for(int row = 0; row < 10; row++){
        for(int col = 0; col < 20; col++){
            int cellvalue = grid[col][row];
            DrawRectangle((row * 30) + 1 ,(col * 30) + 1 , 29, 29, Cellcolor[cellvalue]);
        }
    }
}

bool IscellEmpty(int row,int col){
    if(grid[col][row] == 0){
        return false;
    }
    return true;
}
bool Rowcomplete(int row){
    int complete = 0;
    for(int col = 0; col < col_offset; col++ ){
        if(grid[row][col] != 0){
            complete++;
        }
    }
    if(complete == 10){
        return true;
    }
    return false;
}

void ShiftRow(int row){
    for(int col = col_offset - 1; col >= 0; col--){
        if(IscellEmpty(col, row)){
            grid[col-1][row] = grid[col][row];
            grid[col][row] = 0;
        }
    }
    
}
void deleteRow(){
    for(int row = row_offset - 1; row >=0; row--){
        if(Rowcomplete(row)){
            for(int col = 0;col < col_offset; col++){
                grid[row][col] = 0;
            }
        }
        ShiftRow(row);
    }
}


