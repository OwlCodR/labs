#include "ai.h"
#include <qDebug>
#include <stdlib.h>
#include <time.h>

// It should be initialized before using
std::set<Position> AI::availableMoves;

Position AI::getMovePosition(TicTacToeMap map, Camera camera, int winScore)
{
    srand(time(NULL));
    while (true) {
        Position position = camera.getPosition() +
                Position(
                    rand() % camera.getVisibleMapSize() - camera.getVisibleMapSize() / 2,
                    rand() % camera.getVisibleMapSize() - camera.getVisibleMapSize() / 2
                );

        qDebug() << "AI generated position: " << position.x << position.y;

        if (!map.getSymbol(position)) {
            return position;
        }
    }
}

Position AI::min() {
    return Position(0, 0);
}

Position AI::max() {
    return Position(0, 0);
}

void AI::updateAvailableMoves(TicTacToeMap map, int winScore, Position lastMove)
{
    qDebug() << "Last Move:" << lastMove.x << lastMove.y;
    AI::availableMoves.erase(lastMove);

    for (int i(-winScore + 1); i < winScore; i++) {
        for (int j(-winScore + 1); j < winScore; j++) {
            Position move = Position(lastMove.x + i, lastMove.y + j);
            qDebug() << "Possible move checking: " << move.x << move.y;

            if (!map.getSymbol(move)) {
                AI::availableMoves.insert(move);
                qDebug() << "Possible move added";
            }
        }
    }
}
