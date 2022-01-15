#include "ai.h"
#include <stdlib.h>
#include <time.h>

AI::AI() {

}

Position AI::getMovePosition(TicTacToeMap& map, Camera camera, char symbol)
{
    while (true) {
        Position position = Position(
                    rand() % camera.getVisibleMapSize() - camera.getVisibleMapSize() / 2,
                    rand() % camera.getVisibleMapSize() - camera.getVisibleMapSize() / 2
                    );
        if (!map.getSymbol(position)) {
            return position;
        }
    }
}


