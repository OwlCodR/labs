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
    game.camera.setPosition(Position(game.camera.getVisibleMapSize() / 2, game.camera.getVisibleMapSize() / 2));

    game.updateMap();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent* event) {
    if (event->key() == Qt::Key_Left) {
        this->game.camera.setVisibleMapSize(game.camera.getVisibleMapSize() + 1);
        this->game.updateMap();
    }

    if (event->key() == Qt::Key_Right) {
        this->game.camera.setVisibleMapSize(game.camera.getVisibleMapSize() - 1);
        this->game.updateMap();
    }
}

