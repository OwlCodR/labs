#include "ai.h"
#include "game.h"
#include <QDebug>
#include <stdlib.h>
#include <time.h>

int AI::maxDepth = 4;

/**
 * @brief AI::getMovePosition Calculates position of the best move.
 * @param map Actual TicTacToeMap map.
 * @param camera Camera object (temporary)
 * @param winScore Count of the cells of one symbol to collect in one line to win.
 * @return position of the best move.
 */
Position AI::getMovePosition(std::set<std::pair<int, int>> availableMoves, TicTacToeMap map, Position lastSymbolPosition, int winScore)
{
//    srand(time(NULL));
//        while (true) {
//            Position position =
//                    Position(
//                        rand() % 3 - 3 / 2,
//                        rand() % 3 - 3 / 2
//                    );

//            qDebug() << "AI generated position: " << position.x << position.y;

    std::pair<Position, int> bestMove = max(availableMoves, map, lastSymbolPosition, winScore, 0);
    // qDebug() << "Best move: position(" << bestMove.first.x << bestMove.first.y << ")\nScore: " << bestMove.second;

    return bestMove.first;
}

std::pair<Position, int> AI::min(std::set<std::pair<int, int>> availableMoves, TicTacToeMap map, Position lastSymbolPosition, int winScore, int depth) {

    if (depth == maxDepth) {
//        qDebug() << "\nMax depth! Return 0 at" << lastSymbolPosition.x << lastSymbolPosition.y << "Depth: " << depth << "==" << AI::maxDepth;
        return std::make_pair(lastSymbolPosition, 0);
    }

    char lastSymbol = map.getSymbol(lastSymbolPosition);
    std::pair<Position, int> minPair(Position(0, 0), 2);

//    qDebug() << "availableMoves:";
//    for (auto it = AI::availableMoves.begin(); it != AI::availableMoves.end(); it++) {
//        qDebug() << it->first << it->second;
//    }

    for (auto it = availableMoves.begin(); it != availableMoves.end(); it++) {
//        qDebug() << "\nPlayer is trying to move at" << it->first << it->second;
        Position currentMove = Position(it->first, it->second);

        if (map.isSymbolAt(currentMove)) {
            continue;
        }

        map.setSymbol(currentMove, Game::getSwitchedSymbol(lastSymbol));

        if (Game::isCurrentPlayerWinner(map, currentMove, winScore)) {
            return std::make_pair(currentMove, -1);
        }
//        else {
//            qDebug() << "Player hasn't won at this position.";
//        }

        std::set<std::pair<int, int>> availableMovesBuffer = availableMoves;
        addAvailableMoves(availableMovesBuffer, map, winScore, currentMove);

        // qDebug() << "Now lets see best bot's move";
        std::pair<Position, int> maxPair = max(availableMovesBuffer, map, currentMove, winScore, depth + 1);
        // qDebug() << "Best bot's move is " << maxPair.first.x << maxPair.first.y;

        if (maxPair.second < minPair.second) {
            minPair = maxPair;

            // qDebug() << "Founded better move!" << minPair.first.x << minPair.first.y;
        }

        // qDebug() << "Ok. Remove this move.";
        map.removeSymbol(currentMove);
    }

    // qDebug() << "Return best player's move with score" << minPair.second << "on" << minPair.first.x << minPair.first.y;
    return minPair;
}

/**
 * @brief AI::max This function will maximize AI's score.
 * @return std::pair<Possition, int> where Position is the position of the best move,
 * int is the score of that move.
 */
std::pair<Position, int> AI::max(std::set<std::pair<int, int>> availableMoves, TicTacToeMap map, Position lastSymbolPosition, int winScore, int depth) {
    if (depth == AI::maxDepth) {
        // qDebug() << "\nMax depth! Return 0 at" << lastSymbolPosition.x << lastSymbolPosition.y << "Depth: " << depth << "==" << AI::maxDepth;
        return std::make_pair(lastSymbolPosition, 0);
    }

    char lastSymbol = map.getSymbol(lastSymbolPosition);
    std::pair<Position, int> maxPair(Position(0, 0), -2);

//    qDebug() << "availableMoves:";
//    for (auto it = AI::availableMoves.begin(); it != AI::availableMoves.end(); it++) {
//        qDebug() << it->first << it->second;
//    }

    for (auto it = availableMoves.begin(); it != availableMoves.end(); it++) {
//        qDebug() << "\nBot is trying to move at" << it->first << it->second;

        Position currentMove = Position(it->first, it->second);

        if (map.isSymbolAt(currentMove)) {
            continue;
        }

        map.setSymbol(currentMove, Game::getSwitchedSymbol(lastSymbol));

        if (Game::isCurrentPlayerWinner(map, currentMove, winScore)) {
//            qDebug() << "Oh bot won at this position!";
            return std::make_pair(currentMove, 1);
        } else {
//            qDebug() << "Bot hasn't won at this position.";
        }

        std::set<std::pair<int, int>> availableMovesBuffer = availableMoves;
        addAvailableMoves(availableMovesBuffer, map, winScore, currentMove);

//        qDebug() << "Now let's see best player's move";
        std::pair<Position, int> minPair = min(availableMovesBuffer, map, currentMove, winScore, depth + 1);
//        qDebug() << "Best player's move is " << maxPair.first.x << maxPair.first.y;

        if (minPair.second > maxPair.second) {
            maxPair = minPair;

//            qDebug() << "Founded better move!" << minPair.first.x << minPair.first.y;
        }

//        qDebug() << "Ok. Remove this move.";
        map.removeSymbol(currentMove);
    }

//    qDebug() << "Return best bot's move with score" << maxPair.second << "on" << maxPair.first.x << maxPair.first.y;
    return maxPair;
}

void AI::addAvailableMoves(std::set<std::pair<int, int>>& availableMoves, TicTacToeMap map, int winScore, Position lastMove) {
    // qDebug() << "\nLast Move:" << lastMove.x << lastMove.y;

    for (int i(-winScore + 1); i < winScore; i++) {
        for (int j(-winScore + 1); j < winScore; j++) {
            Position move = Position(lastMove.x + i, lastMove.y + j);
            // qDebug() << "Possible move checking: " << move.x << move.y;

            if (!map.isSymbolAt(move)) {
                availableMoves.insert(std::make_pair(move.x, move.y));
                // qDebug() << "Possible move" << move.x << move.y << "added";
            }
        }
    }
}

/// @TODO Update comments
