#ifndef AI_H
#define AI_H

#include "tictactoemap.h"

class AI
{
public:
    AI();
    static void move(TicTacToeMap map, char symbol);
};

#endif // AI_H
