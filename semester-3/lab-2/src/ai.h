#ifndef AI_H
#define AI_H

#include "camera.h"
#include "tictactoemap.h"

class AI
{
public:
    AI();
    static Position getMovePosition(TicTacToeMap& map, Camera camera, char symbol);
};

#endif // AI_H
