#include "camera.h"

#include <string>

Camera::Camera()
{

}

Camera::Camera(int x, int y)
{
    this->currentPosition.x = x;
    this->currentPosition.y = y;
}

void Camera::setPosition(Position position)
{
    this->currentPosition.x = position.x;
    this->currentPosition.y = position.y;
}

Position Camera::getPosition()
{
    return this->currentPosition;
}

/**
 * @brief Camera::toMapPos Converts camera position to map indexes
 * @param map Game's map
 * @param position Position of Camera
 * @return Position where x is i index, y is j index
 */
Position Camera::toMapPos(TicTacToeMap map, Position position)
{
    return Position(map.getSize() / 2 + position.x, map.getSize() / 2 - position.y);
}
