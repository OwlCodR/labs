#include "ai.h"
#include "game.h"
#include <QDebug>
#include <stdlib.h>
#include <time.h>

int AI::maxDepth = 3;
int counter = 0;

/**
 * @brief AI::getMovePosition Calculates the best move using minimax algorithm.
 * @param availableMoves std::set<std::pair<int, int>> which contains available moves after last move.
 * @param map TicTacToe actual map.
 * @param lastSymbolPosition Position of the last symbol.
 * @param winScore The number to line up to win.
 * @return Position of the best move.
 */
Position AI::getMovePosition(std::set<std::pair<int, int>> availableMoves, TicTacToeMap map, Position lastSymbolPosition, int winScore)
{
    std::pair<Position, int> bestMove = max(availableMoves, map, lastSymbolPosition, winScore, 0);
    qDebug() << "Count of calls: " <<  counter;

    return bestMove.first;
}

/**
 * @brief AI::min Min function which simulates player.
 * @param availableMoves std::set<std::pair<int, int>> which contains available moves after last move.
 * @param map TicTacToe actual map.
 * @param lastSymbolPosition Position of the last symbol.
 * @param winScore The number to line up to win.
 * @param depth Current depth of the tree.
 * @return Move with the min score.
 */
std::pair<Position, int> AI::min(std::set<std::pair<int, int>> availableMoves, TicTacToeMap map, Position lastSymbolPosition, int winScore, int depth) {
    counter++;

    if (depth == maxDepth) {
        return std::make_pair(lastSymbolPosition, 0);
    }

    char lastSymbol = map.getSymbol(lastSymbolPosition);
    std::pair<Position, int> minPair(Position(0, 0), 2);

    for (auto it = availableMoves.begin(); it != availableMoves.end(); it++) {
        Position currentMove = Position(it->first, it->second);

        if (map.isSymbolAt(currentMove)) {
            continue;
        }

        map.setSymbol(currentMove, Game::getSwitchedSymbol(lastSymbol));

        if (Game::isCurrentPlayerWinner(map, currentMove, winScore)) {
            return std::make_pair(currentMove, -1);
        }

        std::set<std::pair<int, int>> availableMovesBuffer = availableMoves;
        addAvailableMoves(availableMovesBuffer, map, winScore, currentMove);

        std::pair<Position, int> maxPair = max(availableMovesBuffer, map, currentMove, winScore, depth + 1);

        if (maxPair.second < minPair.second) {
            minPair.first = currentMove;
            minPair.second = maxPair.second;
        }

        map.removeSymbol(currentMove);
    }

    return minPair;
}

/**
 * @brief AI::max Max function which simulates AI.
 * @param availableMoves std::set<std::pair<int, int>> which contains available moves after last move.
 * @param map TicTacToe actual map.
 * @param lastSymbolPosition Position of the last symbol.
 * @param winScore The number to line up to win.
 * @param depth Current depth of the tree.
 * @return Move with the max score.
 */
std::pair<Position, int> AI::max(std::set<std::pair<int, int>> availableMoves, TicTacToeMap map, Position lastSymbolPosition, int winScore, int depth) {
    counter++;

    if (depth == AI::maxDepth) {
        return std::make_pair(lastSymbolPosition, 0);
    }

    char lastSymbol = map.getSymbol(lastSymbolPosition);
    std::pair<Position, int> maxPair(Position(0, 0), -2);

    for (auto it = availableMoves.begin(); it != availableMoves.end(); it++) {
        Position currentMove = Position(it->first, it->second);

        if (map.isSymbolAt(currentMove)) {
            continue;
        }

        map.setSymbol(currentMove, Game::getSwitchedSymbol(lastSymbol));

        if (Game::isCurrentPlayerWinner(map, currentMove, winScore)) {
            return std::make_pair(currentMove, 1);
        }

        std::set<std::pair<int, int>> availableMovesBuffer = availableMoves;
        addAvailableMoves(availableMovesBuffer, map, winScore, currentMove);

        std::pair<Position, int> minPair = min(availableMovesBuffer, map, currentMove, winScore, depth + 1);

        if (minPair.second > maxPair.second) {
            maxPair.first = currentMove;
            maxPair.second = minPair.second;
        }

        map.removeSymbol(currentMove);
    }

    if (depth == 0) {
        qDebug() << "AI best is " << maxPair.first.x << maxPair.first.y << "|" << maxPair.second;
    }
    // qDebug() << "AI best is " << maxPair.first.x << maxPair.first.y << "|" << maxPair.second;
    return maxPair;
}

/**
 * @brief AI::addAvailableMoves Finds and adds positions to `availableMoves` from area of last move.
 * @param availableMoves Link to the `availableMoves` to add there new positions.
 * @param map TicTacToe actual map.
 * @param winScore The number to line up to win.
 * @param lastMove Position of the last move.
 */
void AI::addAvailableMoves(std::set<std::pair<int, int>>& availableMoves, TicTacToeMap map, int winScore, Position lastMove) {

    for (int i(-winScore + 1); i < winScore; i++) {
        for (int j(-winScore + 1); j < winScore; j++) {
            Position move = Position(lastMove.x + i, lastMove.y + j);

            if (!map.isSymbolAt(move)) {
                availableMoves.insert(std::make_pair(move.x, move.y));
            }
        }
    }
}
