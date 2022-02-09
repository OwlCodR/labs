#ifndef AI_H
#define AI_H

#include "camera.h"
#include "tictactoemap.h"

#include <set>

class AI
{
public:
    typedef std::set<std::pair<int, int>> PositionScoreSet;

    static void addAvailableMoves(PositionScoreSet& availableMoves, TicTacToeMap map, Position lastMove, int winScore);
    static Position getMovePosition(PositionScoreSet availableMoves, TicTacToeMap map, Position lastSymbolPosition);
    static std::pair<Position, int> min(PositionScoreSet availableMoves, TicTacToeMap map, Position lastSymbolPosition, int alpha, int beta, int depth);
    static std::pair<Position, int> max(PositionScoreSet availableMoves, TicTacToeMap map, Position lastSymbolPosition, int alpha, int beta, int depth);

    // Default value: 3
    static int maxDepth;

    // Default value: 3
    static int winScore;
};

#endif // AI_H
