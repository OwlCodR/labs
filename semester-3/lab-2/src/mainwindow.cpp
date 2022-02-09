#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <vector>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    game.addPlayer(Game::PlayerType::Human);
    game.addPlayer(Game::PlayerType::AI);
    game.setCurrentSymbol(Game::Symbol::X);
    game.setCurrentPlayer(Game::PlayerType::Human);
    game.getCamera().setVisibleMapSize(11);
    game.getCamera().setPosition(Position(0, 0));
    game.setCurrentState(Game::State::Waiting);
    game.setWinScore(3);
    game.setGridLayout(ui->gridLayout);

    game.updateMap();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent* event) {
    // Do not forget to set NoFocus policy to make arrows work properly

    /// @TODO It is better to add new fields without removing all cells from gridLayout
    if (event->key() == Qt::Key_Up) {
        game.clearGridLayout();

        game.getCamera().setVisibleMapSize(game.getCamera().getVisibleMapSize() - 2);
        game.updateMap();
    }

    if (event->key() == Qt::Key_Down) {
        game.clearGridLayout();

        game.getCamera().setVisibleMapSize(game.getCamera().getVisibleMapSize() + 2);
        game.updateMap();
    }

    if (game.getCurrentState() != Game::State::InProgress)  {
        // DON'T MOVE THIS IF
        return;
    }

    if (event->key() == Qt::Key_W) {
        game.getCamera().deltaPosition(0, 1);
        game.updateMap();
    }

    if (event->key() == Qt::Key_A) {
        game.getCamera().deltaPosition(-1, 0);
        game.updateMap();
    }

    if (event->key() == Qt::Key_S) {
        game.getCamera().deltaPosition(0, -1);
        game.updateMap();
    }

    if (event->key() == Qt::Key_D) {
        game.getCamera().deltaPosition(1, 0);
        game.updateMap();
    }
}


void MainWindow::on_pushButton_X_clicked() {
    if (game.getCurrentState() != Game::State::Waiting) {
        ui->pushButton_X->setChecked(true);
        return;
    }

    ui->pushButton_X->setChecked(true);
    ui->pushButton_O->setCheckable(false);

    game.setCurrentSymbol(Game::Symbol::X);
    game.setCurrentPlayer(Game::PlayerType::Human);
    game.setCurrentState(Game::State::InProgress);
}


void MainWindow::on_pushButton_O_clicked() {
    if (game.getCurrentState() != Game::State::Waiting) {
        ui->pushButton_O->setChecked(true);
        return;
    }

    ui->pushButton_O->setChecked(true);
    ui->pushButton_X->setCheckable(false);

    game.setCurrentSymbol(Game::Symbol::O);
    game.setCurrentPlayer(Game::PlayerType::AI);
    game.setCurrentState(Game::State::InProgress);
    game.move(Position(0, 0));
}


void MainWindow::on_pushButton_W_clicked() {
    game.getCamera().deltaPosition(0, 1);
    game.updateMap();
}


void MainWindow::on_pushButton_A_clicked() {
    game.getCamera().deltaPosition(-1, 0);
    game.updateMap();
}


void MainWindow::on_pushButton_S_clicked() {
    game.getCamera().deltaPosition(0, -1);
    game.updateMap();
}


void MainWindow::on_pushButton_D_clicked() {
    game.getCamera().deltaPosition(1, 0);
    game.updateMap();
}


void MainWindow::on_pushButton_Restart_clicked() {
    game.restart();

    ui->pushButton_O->setChecked(false);
    ui->pushButton_X->setChecked(false);

    ui->pushButton_O->setCheckable(true);
    ui->pushButton_X->setCheckable(true);
}

