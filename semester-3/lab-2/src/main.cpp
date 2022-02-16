#include "mainwindow.h"

#include <QApplication>
#include <QTest>

#include <tests/game_test.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // QTest::qExec(new GameTest, argc, argv);

    MainWindow w;
    w.show();
    return a.exec();
}
