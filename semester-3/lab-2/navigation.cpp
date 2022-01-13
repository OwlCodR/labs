#include "navigation.h"
#include "game.h"
#include <QApplication>
#include <QKeyEvent>

Navigation::Navigation(QWidget* parent) : QWidget(parent)
{

}

void Navigation::keyPressEvent(QKeyEvent* event) {
   if (event->key() == Qt::LeftArrow) {

   }
}
