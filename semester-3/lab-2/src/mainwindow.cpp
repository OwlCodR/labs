#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <vector>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    game.addPlayer(Game::PlayerType::Human);
    game.addPlayer(Game::PlayerType::AI);
    game.setCurrentSymbol(Game::Symbol::X);
    game.gridLayout = ui->gridLayout;
    game.setCurrentPlayer(Game::PlayerType::Human);
    game.camera.setVisibleMapSize(11);
    game.camera.setPosition(Position(0, 0));
    game.setCurrentState(Game::State::Waiting);
    game.setWinScore(4);

    game.updateMap();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent* event) {
    if (event->key() == Qt::Key_Up) {
        QLayoutItem* item;
        while ((item = game.gridLayout->takeAt(0)) != NULL)
        {
            delete item->widget();
            delete item;
        }

        this->game.camera.setVisibleMapSize(game.camera.getVisibleMapSize() - 2);
        this->game.updateMap();
    }

    if (event->key() == Qt::Key_Down) {
        this->game.camera.setVisibleMapSize(game.camera.getVisibleMapSize() + 2);
        this->game.updateMap();
    }

    if (game.getCurrentState() != Game::State::InProgress)  {
        // DON'T MOVE THIS IF
        return;
    }

    if (event->key() == Qt::Key_W) {
        this->game.camera.setPosition(Position(game.camera.getPosition().x, game.camera.getPosition().y + 1));
        this->game.updateMap();
    }

    if (event->key() == Qt::Key_A) {
        this->game.camera.setPosition(Position(game.camera.getPosition().x - 1, game.camera.getPosition().y));
        this->game.updateMap();
    }

    if (event->key() == Qt::Key_S) {
        this->game.camera.setPosition(Position(game.camera.getPosition().x, game.camera.getPosition().y - 1));
        this->game.updateMap();
    }

    if (event->key() == Qt::Key_D) {
        this->game.camera.setPosition(Position(game.camera.getPosition().x + 1, game.camera.getPosition().y));
        this->game.updateMap();
    }
}


void MainWindow::on_pushButton_X_clicked() {
    // @TODO Code duplicate!
    if (game.getCurrentState() == Game::State::InProgress)  {
        // Save state
        if (ui->pushButton_X->isChecked())
            ui->pushButton_X->setChecked(false);
        else
            ui->pushButton_X->setChecked(true);
        return;
    }

    this->game.setCurrentSymbol(Game::Symbol::X);
    ui->pushButton_O->setChecked(false);

    game.setCurrentState(Game::State::InProgress);
}


void MainWindow::on_pushButton_O_clicked() {
    // @TODO Code duplicate!
    if (game.getCurrentState() == Game::State::InProgress)  {
        // Save state
        if (ui->pushButton_O->isChecked())
            ui->pushButton_O->setChecked(false);
        else
            ui->pushButton_O->setChecked(true);
        return;
    }

    this->game.setCurrentSymbol(Game::Symbol::O);
    ui->pushButton_X->setChecked(false);

    game.setCurrentState(Game::State::InProgress);
}


void MainWindow::on_pushButton_W_clicked() {
    this->game.camera.setPosition(Position(game.camera.getPosition().x, game.camera.getPosition().y + 1));
    this->game.updateMap();
}


void MainWindow::on_pushButton_A_clicked() {
    this->game.camera.setPosition(Position(game.camera.getPosition().x - 1, game.camera.getPosition().y));
    this->game.updateMap();
}


void MainWindow::on_pushButton_S_clicked() {
    this->game.camera.setPosition(Position(game.camera.getPosition().x, game.camera.getPosition().y - 1));
    this->game.updateMap();
}


void MainWindow::on_pushButton_D_clicked() {
    this->game.camera.setPosition(Position(game.camera.getPosition().x + 1, game.camera.getPosition().y));
    this->game.updateMap();
}

