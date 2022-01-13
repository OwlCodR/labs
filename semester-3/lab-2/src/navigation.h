#ifndef NAVIGATION_H
#define NAVIGATION_H

#include <QWidget>

class Navigation : public QWidget
{
public:
  Navigation(QWidget* parent = 0);
private:
  void keyPressEvent(QKeyEvent* e);
};

#endif // NAVIGATION_H
