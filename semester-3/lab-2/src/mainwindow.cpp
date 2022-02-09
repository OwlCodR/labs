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
    game.camera.setVisibleMapSize(11);
    game.camera.setPosition(Position(0, 0));
    game.setCurrentState(Game::State::Waiting);
    game.setWinScore(3);
    game.gridLayout = ui->gridLayout;

    game.updateMap();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::removeAllFrom(QGridLayout* layout) {
    QLayoutItem* item;
    while ((item = layout->takeAt(0)) != nullptr)
    {
        delete item->widget();
        delete item;
    }
}

void MainWindow::keyPressEvent(QKeyEvent* event) {
    // Do not forget to set NoFocus policy to make arrows work properly

    /// @TODO It is better to add new fields without removing all cells from gridLayout
    if (event->key() == Qt::Key_Up) {
        removeAllFrom(game.gridLayout);

        this->game.camera.setVisibleMapSize(game.camera.getVisibleMapSize() - 2);
        this->game.updateMap();
    }

    if (event->key() == Qt::Key_Down) {
        removeAllFrom(game.gridLayout);

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
    if (game.getCurrentState() == Game::State::InProgress) {
        return;
    }

    ui->pushButton_X->setChecked(true);
    ui->pushButton_O->setCheckable(false);

    game.setCurrentSymbol(Game::Symbol::X);
    game.setCurrentPlayer(Game::PlayerType::Human);
    game.setCurrentState(Game::State::InProgress);
}


void MainWindow::on_pushButton_O_clicked() {
    if (game.getCurrentState() == Game::State::InProgress) {
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


void MainWindow::on_pushButton_Restart_clicked() {
    game.restart();

    ui->pushButton_O->setChecked(false);
    ui->pushButton_X->setChecked(false);

    ui->pushButton_O->setCheckable(true);
    ui->pushButton_X->setCheckable(true);
}

