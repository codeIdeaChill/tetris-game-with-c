#include "lib/map.h"
#include "lib/rotition.h"

void GameInfo(Font font){
    DrawTextEx(font, "INFO:"                , (Vector2){350, 350} , 40.0f   , 2.0f  , RED);
    DrawTextEx(font, "KEY UP: ROTITE "      , (Vector2){304, 400} , 16.0f   , 2.0f  , WHITE);
    DrawTextEx(font, "KEY DOWN: MOVE DOWN"  , (Vector2){304, 420} , 16.0f   , 2.0f  , WHITE);
    DrawTextEx(font, "KEY RIGHT: MOVE RIGHT", (Vector2){304, 440} , 16.0f   , 2.0f  , WHITE);
    DrawTextEx(font, "KEY LEFT: MOVE LEFT"  , (Vector2){304, 460} , 16.0f   , 2.0f  , WHITE);
    DrawTextEx(font, "KEY R: REST"          , (Vector2){304, 480} , 16.0f   , 2.0f  , WHITE);
}

