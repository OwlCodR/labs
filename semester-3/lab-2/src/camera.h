#ifndef CAMERA_H
#define CAMERA_H

#include "tictactoemap.h"
#include "position.h"
#include <vector>

/**
 * @brief The Camera class
 */
class Camera
{
public:
    Camera();
    Camera(int x, int y);

    void setVisibleMapSize(int size);
    int getVisibleMapSize();

    void setPosition(Position position);
    Position getPosition();

    Position toMapPos(TicTacToeMap map, Position position);
private:
    Position currentPosition;
    int visibleMapSize;
};

#endif // CAMERA_H
