#ifndef AI_H
#define AI_H

#include "camera.h"
#include "tictactoemap.h"

#include <set>

class AI
{
public:
    static void updateAvailableMoves(TicTacToeMap map, int winScore, Position lastMove);
    static Position getMovePosition(TicTacToeMap map, Camera camera, int winScore);
    static Position min();
    static Position max();

private:
    static std::set<Position> availableMoves;
};

#endif // AI_H
