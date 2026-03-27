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
//check if the grid has value 0 in row and column cordinate
bool IscellEmpty(int row,int col){
    if(grid[col][row] == 0){
        return false;
    }
    return true;
}

//check if the row was completed and delete it and move it down

bool Rowcomplete(int row){
    for(int col = 0; col < col_offset; col++ ){
        if(grid[row][col] == 0){
            return false;
        }
    }
    return true;
}


//move row down
void MoveRowDown(int row, int rowCount){
    for(int col = col_offset - 1; col >= 0; col--){
        grid[row + rowCount][col] = grid[row][col];
        grid[row][col] = 0;
    }
    
}

//delete row
void deleteRow(int row){
    for(int col = 0;col < col_offset; col++){
        grid[row][col] = 0;
    }
}

//delete full row 
int DeleteFullRows(){
    int completed = 0;
    for(int row = row_offset -1; row >=0; row--){
        if(Rowcomplete(row)){
            deleteRow(row);
            completed++;
        }else if(completed > 0){
            MoveRowDown(row, completed);
        }
    }
    return completed;
}

