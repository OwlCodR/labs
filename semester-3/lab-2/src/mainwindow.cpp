#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <vector>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    game.addPlayer(Game::Human);
    game.addPlayer(Game::AI);
    game.setCurrentSymbol('X');
    game.gridLayout = ui->gridLayout;
    game.setCurrentPlayer(Game::Human);
    game.camera.setVisibleMapSize(3);
    game.camera.setPosition(Position(0, 0));

    game.updateMap();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent* event) {
    if (event->key() == Qt::Key_Left) {
        this->game.camera.setVisibleMapSize(game.camera.getVisibleMapSize() + 2);
        this->game.updateMap();
    }

    if (event->key() == Qt::Key_Right) {
        QLayoutItem* item;
        while ((item = game.gridLayout->takeAt(0)) != NULL)
        {
            delete item->widget();
            delete item;
        }

        this->game.camera.setVisibleMapSize(game.camera.getVisibleMapSize() - 2);
        this->game.updateMap();
    }

    if (event->key() == Qt::Key_Up) {
        this->game.move(Position(1, 1));
        this->game.updateCell(Position(1, 1));
    }

    if (event->key() == Qt::Key_Down) {
        this->game.move(Position(-1, 0));
        this->game.updateCell(Position(-1, 0));
    }
}

