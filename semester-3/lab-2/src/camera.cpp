#include "camera.h"

#include <QDebug>
#include <string>

Camera::Camera()
{

}

Camera::Camera(int x, int y)
{
    this->currentPosition.x = x;
    this->currentPosition.y = y;
}

/**
 * @brief Camera::setVisibleMapSize Sets size of the visible map area.
 * @param size Only odd number.
 */
void Camera::setVisibleMapSize(int size)
{
    if (size % 2 == 0) {
        qWarning() << "New visibe area is not odd!";
        return;
    }

    if (size < 3) {
        qWarning() << "New visibe area is too small!";
        return;
    }

    this->visibleMapSize = size;
    qDebug() << "New visibe area: " << size;
}

int Camera::getVisibleMapSize()
{
    return this->visibleMapSize;
}

void Camera::setPosition(Position position)
{
    this->currentPosition.x = position.x;
    this->currentPosition.y = position.y;
}

Position Camera::getPosition()
{
    return currentPosition;
}
