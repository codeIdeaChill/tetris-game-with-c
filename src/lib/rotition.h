#pragma once
#include "../include/raylib.h"
#include "blocks.h"
#include "map.h"

//init rotition state as 0
static int rot = 0;
void MoveRight(Blocks* block, int rot);
void MoveLeft(Blocks* block, int rot);
void MoveDown(Blocks* block, int rot);
void LockBlock(Blocks block, int rot);
int rotState(Blocks currentBlock, int rot);
void handleEvent(Blocks* block, int rot);
void newBlock(Blocks* block,int rot);
void DrawNextBlock(Blocks* block);
void UpdateScore();
