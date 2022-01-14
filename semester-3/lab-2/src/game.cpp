#include "game.h"

#include <QPushButton>
#include <QDebug>

/**
 * @brief Game::Game Default constructor
 */
Game::Game() {

}

/**
 * @brief Game::start Starts the game with given data
 * @param firstPlayerIndex Index of the player in `players` which will make first move
 * @param firstPlayerSymbol Symbol (char) of the first player
 */
void Game::start(int firstPlayerIndex, char firstPlayerSymbol)
{
    this->currentPlayer = players[firstPlayerIndex];
    this->currentSymbol = firstPlayerSymbol;
}

/**
 * @brief Game::move Makes move, updates player, symbol and checks winner
 * @param position Position of the symbol (char)
 * @param symbol Char 'X' or 'O'
 */
void Game::move(Position position, char symbol)
{
    setSymbol(position, symbol);

    checkWinner();
    switchCurrentPlayer();
    switchCurrentSymbol();
}

/**
 * @brief Game::setSymbol private function to set symbol to the TicTacToeMap
 * @param Position Position of the symbol
 * @param symbol Char 'X' or 'O'
 */
void Game::setSymbol(Position position, char symbol)
{
    this->map.setSymbol(position, symbol);
}

/**
 * @brief Game::switchCurrentPlayer Switches current player to the another one
 */
void Game::switchCurrentPlayer()
{
    if (currentPlayer == 1) {
        currentPlayer--;
    } else {
        currentPlayer++;
    }
}

/**
 * @brief Game::switchCurrentSymbol Switches current symbol to the another one
 */
void Game::switchCurrentSymbol()
{
    if (currentSymbol == 'X') {
        currentSymbol = 'O';
    } else {
        currentSymbol = 'X';
    }
}

/**
 * @brief Game::updateMap Redraws visible area of the map
 */
void Game::updateMap()
{
    /// @TODO Optimize it
    int halfOfLength = this->camera.getVisibleMapSize() / 2;

    for (int i(-halfOfLength); i <= halfOfLength; i++) {
        qDebug() << "i = " << i;
        for (int j(-halfOfLength); j <= halfOfLength; j++) {
            QSizePolicy policy;
            policy.setHorizontalPolicy(QSizePolicy::Expanding);
            policy.setVerticalPolicy(QSizePolicy::Expanding);

            QPushButton* button = new QPushButton();
            button->setSizePolicy(policy);
            button->setFocusPolicy(Qt::FocusPolicy::NoFocus);
            //connect(button, SIGNAL(clicked()), this, SLOT(slotButtonClicked()));
            /// @TODO Connect buttons

            Position currentSymbolPosition = Position(i, j) + camera.getPosition();
            if (map.getSymbol(currentSymbolPosition) == 'X') {
                button->setStyleSheet("border-image: url(:res/x.png);");
            } else if (map.getSymbol(currentSymbolPosition) == 'O') {
                button->setStyleSheet("border-image: url(:res/o.png);");
            } else {
                button->setStyleSheet("border-image: url(:res/cell.png);");
            }

            gridLayout->addWidget(button, i + halfOfLength, j + halfOfLength);
            button->show();
        }
    }
}

void Game::addPlayer(PlayerType playerType) {
    players.push_back(playerType);
}

void Game::setCurrentSymbol(char currentSymbol) {
    this->currentSymbol = currentSymbol;
}

void Game::setCurrentPlayer(int currentPlayer) {
    this->currentPlayer = currentPlayer;
}

void Game::checkWinner()
{

}

void Game::stop()
{

}

void Game::stop(int winnerIndex)
{

}

vector<Game::PlayerType> Game::getPlayers()
{
    return this->players;
}

int Game::getCurrentPlayer()
{
    return this->currentPlayer;
}

char Game::getCurrentSymbol()
{
    return this->currentSymbol;
}

void Game::slotButtonClicked(Position position) {
    // setSymbol(x, y, getCurrentSymbol());
    QObject* button = sender();
    //qDebug("CLICKED " + to_string(position.x) + " " + to_string(position.y));
}
