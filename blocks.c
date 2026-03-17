#include "blocks.h"

Blocks LShape(){
    Blocks peice = {
        .id = 1,
        .shape[0] = {
            .shape = {
                {0,1,0,0},
                {0,1,0,0},
                {0,1,1,0},
                {0,0,0,0}
            },
        },
        .shape[1] = {
            .shape = {
                {1,1,1,0},
                {1,0,0,0},
                {0,0,0,0},
                {0,0,0,0}
            },
        },
        .shape[2] = {
            .shape = {
                {1,1,0,0},
                {0,1,0,0},
                {0,1,0,0},
                {0,0,0,0}
            },
        },
        .shape[3] = {
            .shape = {
                {0,0,1,0},
                {1,1,1,0},
                {0,0,0,0},
                {0,0,0,0}
            },
        },
        .position = {5,0},
        .color = Cellcolor[peice.id] 
    };
    return peice;
}
Blocks SShape(){
    Blocks peice = {
        .id = 2,
        .shape[0] = {
            .shape = {
                {0,1,1,0},
                {1,1,0,0},
                {0,0,0,0},
                {0,0,0,0}
            },
        },
        .shape[1] = {
            .shape = {
                {0,1,0,0},
                {0,1,1,0},
                {0,0,1,0},
                {0,0,0,0}
            },
        },
        .shape[2] = {
            .shape = {
                {0,1,1,0},
                {1,1,0,0},
                {0,0,0,0},
                {0,0,0,0}
            },
        },
        .shape[3] = {
            .shape = {
                {0,1,0,0},
                {0,1,1,0},
                {0,0,1,0},
                {0,0,0,0}
            },
        },
        .position = {5,0},
        .color = Cellcolor[peice.id] 
    };
    return peice;
}
Blocks ZShape(){
    Blocks peice = {
        .id = 3,
        .shape[0] = {
            .shape = {
                {1,1,0,0},
                {0,1,1,0},
                {0,0,0,0},
                {0,0,0,0}
            },
        },
        .shape[1] = {
            .shape = {
                {0,0,1,0},
                {0,1,1,0},
                {0,1,0,0},
                {0,0,0,0}
            },
        },
        .shape[2] = {
            .shape = {
                {1,1,0,0},
                {0,1,1,0},
                {0,0,0,0},
                {0,0,0,0}
            },
        },
        .shape[3] = {
            .shape = {
                {0,0,1,0},
                {0,1,1,0},
                {0,1,0,0},
                {0,0,0,0}
            },
        },
        .position = {5,0},
        .color = Cellcolor[peice.id] 
    };
    return peice;
}
Blocks OShape(){
    Blocks peice = {
        .id = 4,
        .shape[0] = {
            .shape = {
                {0,0,0,0},
                {0,1,1,0},
                {0,1,1,0},
                {0,0,0,0}
            },
        },
        .shape[1] = {
            .shape = {
                {0,0,0,0},
                {0,1,1,0},
                {0,1,1,0},
                {0,0,0,0}
            },
        },
        .shape[2] = {
            .shape = {
                {0,0,0,0},
                {0,1,1,0},
                {0,1,1,0},
                {0,0,0,0}
            },
        },
        .shape[3] = {
            .shape = {
                {0,0,0,0},
                {0,1,1,0},
                {0,1,1,0},
                {0,0,0,0}
            },
        },
        .position = {5,-1},
        .color = Cellcolor[peice.id] 
    };
    return peice;
}
Blocks JShape(){
    Blocks peice = {
        .id = 5,
        .shape[0] = {
            .shape = {
                {0,1,0,0},
                {0,1,0,0},
                {1,1,0,0},
                {0,0,0,0}
            },
        },
        .shape[1] = {
            .shape = {
                {1,0,0,0},
                {1,1,1,0},
                {0,0,0,0},
                {0,0,0,0}
            },
        },
        .shape[2] = {
            .shape = {
                {0,1,1,0},
                {0,1,0,0},
                {0,1,0,0},
                {0,0,0,0}
            },
        },
        .shape[3] = {
            .shape = {
                {1,1,1,0},
                {0,0,1,0},
                {0,0,0,0},
                {0,0,0,0}
            },
        },
        .position = {5,0},
        .color = Cellcolor[peice.id] 
    };
    return peice;
}
Blocks TShape(){
    Blocks peice = {
        .id = 6,
        .shape[0] = {
            .shape = {
                {0,0,0,0},
                {1,1,1,0},
                {0,1,0,0},
                {0,0,0,0}
            },
        },
        .shape[1] = {
            .shape = {
                {0,1,0,0},
                {1,1,0,0},
                {0,1,0,0},
                {0,0,0,0}
            },
        },
        .shape[2] = {
            .shape = {
                {0,1,0,0},
                {1,1,1,0},
                {0,0,0,0},
                {0,0,0,0}
            },
        },
        .shape[3] = {
            .shape = {
                {0,1,0,0},
                {0,1,1,0},
                {0,1,0,0},
                {0,0,0,0}
            },
        },
        .position = {5,-1},
        .color = Cellcolor[peice.id] 
    };
    return peice;
}
Blocks IShape(){
    Blocks peice = {
        .id = 7,
        .shape[0] = {
            .shape = {
                {0,1,0,0},
                {0,1,0,0},
                {0,1,0,0},
                {0,1,0,0}
            },
        },
        .shape[1] = {
            .shape = {
                {0,0,0,0},
                {1,1,1,1},
                {0,0,0,0},
                {0,0,0,0}
            },
        },
        .shape[2] = {
            .shape = {
                {0,0,1,0},
                {0,0,1,0},
                {0,0,1,0},
                {0,0,1,0}
            },
        },
        .shape[3] = {
            .shape = {
                {0,0,0,0},
                {0,0,0,0},
                {1,1,1,1},
                {0,0,0,0}
            },
        },
        .position = {4,0},
        .color = Cellcolor[peice.id], 
    };
    return peice;
}
void DrawTetromino(Blocks piece, int cellSize, int rot, int posY, int posX) {
    for (int y = 0; y < SIZE; y++) {
        for (int x = 0; x < SIZE; x++) {
            if (piece.shape[rot].shape[y][x] == 1) {
                // Calculate screen position based on grid position + array offset
                DrawRectangle(
                    (piece.position.x + x + posX) * cellSize + 1,
                    (piece.position.y + y + posY) * cellSize + 1,
                    cellSize - 1, // -1 creates a small gap between blocks
                    cellSize - 1,
                    piece.color
                );
            }
        }
    }
}


void Move(Blocks* self, int x, int y){
    self->position.x += x;
    self->position.y += y;
}

Shapes getallblocks(){
     Shapes blocks = {{TShape(),IShape(), SShape(), ZShape(), JShape(), LShape(), OShape()}};
     return blocks;
}
Blocks GetRandomBlock(){
     Shapes blocks = getallblocks();
     int num =  GetRandomValue(0, 6);
     Blocks block = blocks.blocks[num];

     return block;
}   
