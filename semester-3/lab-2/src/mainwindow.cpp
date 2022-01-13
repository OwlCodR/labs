#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <game.h>
#include <vector>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->game.addPlayer(Game::Human);
    this->game.addPlayer(Game::AI);
    this->game.setCurrentSymbol('X');
    this->game.gridLayout = ui->gridLayout;
    this->game.setCurrentPlayer(Game::Human);
    this->game.visibleMapSize = 3;
    this->game.setCenterPosition(Position(game.visibleMapSize / 2, game.visibleMapSize / 2));

    for (int i(0); i < this->game.visibleMapSize; i++) {
        vector<char> row;
        for (int k(0); k < this->game.visibleMapSize; k++) {
            row.push_back(' ');
        }
        this->game.gameMap.push_back(row);
    }
    this->game.updateMap();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent* event) {
    if (event->key() == Qt::Key_Left) {
        this->game.setCenterPosition(Position(game.getCenterPosition().x, game.getCenterPosition().y));
        this->game.updateMap();
    }
}

