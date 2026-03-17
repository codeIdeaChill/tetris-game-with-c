#pragma once
#include <raylib.h>
#include "blocks.h"
#include "map.h"
static int rot = 0;
void MoveRight(Blocks* block, int rot);
void MoveLeft(Blocks* block, int rot);
void MoveDown(Blocks* block, int rot);
int Undorotition(int rot);
int rotition(int rot);
void handleEvent(Blocks* block, int rot);
