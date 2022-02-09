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

    void deltaPosition(int deltaX, int deltaY);
    void setVisibleMapSize(int size);
    void setPosition(Position position);

    int getVisibleMapSize();
    Position getPosition();
private:
    Position currentPosition;
    int visibleMapSize;
};

#endif // CAMERA_H
