#ifndef AI_H
#define AI_H

#include "camera.h"
#include "tictactoemap.h"

#include <set>

class AI
{
public:
    static void addAvailableMoves(std::set<std::pair<int, int>>& availableMoves, TicTacToeMap map, int winScore, Position lastMove);
    static Position getMovePosition(std::set<std::pair<int, int>> availableMoves, TicTacToeMap map, Position lastSymbolPosition, int winScore);
    static std::pair<Position, int> min(std::set<std::pair<int, int>> availableMoves, TicTacToeMap map, Position lastSymbolPosition, int winScore, int depth);
    static std::pair<Position, int> max(std::set<std::pair<int, int>> availableMoves, TicTacToeMap map, Position lastSymbolPosition, int winScore, int depth);

    static int maxDepth;
};

#endif // AI_H
