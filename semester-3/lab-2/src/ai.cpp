#include "ai.h"
#include "game.h"
#include <QDebug>
#include <stdlib.h>
#include <time.h>

// Default values
int AI::winScore = 0;
int AI::maxDepth = 0;
int counter = 0;

/**
 * @brief AI::getMovePosition Calculates the best move using minimax algorithm.
 * @param availableMoves PositionScoreSet which contains available moves after last move.
 * @param map TicTacToe actual map.
 * @param lastSymbolPosition Position of the last symbol.
 * @param winScore The number to line up to win.
 * @return Position of the best move.
 */
Position AI::getMovePosition(PositionScoreSet availableMoves, TicTacToeMap map, Position lastSymbolPosition)
{
    int alpha = -20;
    int beta = 20;
    counter = 0;
    std::pair<Position, int> bestMove = max(availableMoves, map, lastSymbolPosition, alpha, beta, 0);
    qDebug() << "Count of calls: " <<  counter;

    return bestMove.first;
}

/**
 * @brief AI::min Min function which simulates player.
 * @param availableMoves PositionScoreSet which contains available moves after last move.
 * @param map TicTacToe actual map.
 * @param lastSymbolPosition Position of the last symbol.
 * @param winScore The number to line up to win.
 * @param depth Current depth of the tree.
 * @return Move with the min score.
 */
std::pair<Position, int> AI::min(PositionScoreSet availableMoves, TicTacToeMap map, Position lastSymbolPosition, int alpha, int beta, int depth) {
    // qDebug() << counter++;
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

        PositionScoreSet availableMovesBuffer = availableMoves;
        addAvailableMoves(availableMovesBuffer, map, currentMove, winScore);

        std::pair<Position, int> maxPair = max(availableMovesBuffer, map, currentMove, alpha, beta, depth + 1);

        if (maxPair.second < minPair.second) {
            minPair.first = currentMove;
            minPair.second = maxPair.second;
        }

        if (maxPair.second < beta) {
            beta = maxPair.second;
        }

        if (alpha >= beta) {
            break;
        }

        map.removeSymbol(currentMove);
    }

    return minPair;
}

/**
 * @brief AI::max Max function which simulates AI.
 * @param availableMoves PositionScoreSet which contains available moves after last move.
 * @param map TicTacToe actual map.
 * @param lastSymbolPosition Position of the last symbol.
 * @param winScore The number to line up to win.
 * @param depth Current depth of the tree.
 * @return Move with the max score.
 */
std::pair<Position, int> AI::max(PositionScoreSet availableMoves, TicTacToeMap map, Position lastSymbolPosition, int alpha, int beta, int depth) {
    // qDebug() << counter++;
    counter++;

    if (depth == maxDepth) {
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

        PositionScoreSet availableMovesBuffer = availableMoves;
        addAvailableMoves(availableMovesBuffer, map, currentMove, winScore);

        std::pair<Position, int> minPair = min(availableMovesBuffer, map, currentMove, alpha, beta, depth + 1);

        if (minPair.second > maxPair.second) {
            maxPair.first = currentMove;
            maxPair.second = minPair.second;
        }

        if (minPair.second > alpha) {
            alpha = minPair.second;
        }

        if (alpha >= beta) {
            break;
        }

        map.removeSymbol(currentMove);
    }

    return maxPair;
}

/**
 * @brief AI::addAvailableMoves Finds and adds positions to `availableMoves` from area of last move.
 * @param availableMoves Link to the `availableMoves` to add there new positions.
 * @param map TicTacToe actual map.
 * @param winScore The number to line up to win.
 * @param lastMove Position of the last move.
 */
void AI::addAvailableMoves(PositionScoreSet& availableMoves, TicTacToeMap map, Position lastMove, int winScore) {
    for (int i(-winScore + 1); i < winScore; i++) {
        for (int j(-winScore + 1); j < winScore; j++) {
            Position move = Position(lastMove.x + i, lastMove.y + j);

            if (!map.isSymbolAt(move)) {
                availableMoves.insert(std::make_pair(move.x, move.y));
            }
        }
    }
}

/*
 * Minimax:
 * Count of calls: 35801
 * Count of calls: 101602
 * Count of calls: 195405
 * Count of calls: 209395
 *
 * Minimax with alpha-beta:
 * Count of calls: 1283
 * Count of calls: 11948
 * Count of calls: 26136
 * Count of calls: 40126
 */
