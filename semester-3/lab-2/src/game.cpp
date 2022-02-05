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
void Game::start(int firstPlayerIndex, Symbol firstPlayerSymbol)
{
    this->currentPlayer = players[firstPlayerIndex];
    this->currentSymbol = firstPlayerSymbol;
}

/**
 * @brief Game::move Makes move, updates player, symbol and checks winner
 * @param position Position of the symbol (char)
 */
void Game::move(Position position)
{
    if (getCurrentState() != State::InProgress)
        return;

    setSymbol(position, getCurrentSymbol());
    setAvailableMoves();

    qDebug() << "isCellVisible(" << position.x << "" << position.y << ") = " << isCellVisible(position);
    if (isCellVisible(position))
        updateCell(position);

    if (isCurrentPlayerWinner()) {
        stop();
        return;
    }

    switchCurrentPlayer();
    switchCurrentSymbol();

    if (players[getCurrentPlayer()] == PlayerType::AI) {
        move(AI::getMovePosition(getAvailableMoves(), map, getLastSymbolPosition(), winScore));
    }
}

/**
 * @brief Game::setSymbol Sets symbol to the TicTacToeMap and updates lastSymbolPosition.
 * @param Position Position of the symbol.
 * @param symbol Char 'X' or 'O'.
 */
void Game::setSymbol(Position position, Symbol symbol)
{
    if (map.isSymbolAt(position)) {
        qWarning() << "[Warning] There is already another symbol!";
        return;
    }

    if (symbol == Symbol::X)
        this->map.setSymbol(position, 'X');
    else
        this->map.setSymbol(position, 'O');
    setLastSymbolPosition(position);
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

    qInfo() << "Current player: " << currentPlayer;
}

/**
 * @brief Game::switchCurrentSymbol Switches current symbol to the another one
 */
void Game::switchCurrentSymbol()
{
    if (currentSymbol == Symbol::X) {
        currentSymbol = Symbol::O;
    } else {
        currentSymbol = Symbol::X;
    }

    qInfo() << "Current symbol: " << currentSymbol;
}

/**
 * @brief Game::updateMap Updates all buttons from the TicTacToeMap with visible map size from Camera.
 */
void Game::updateMap()
{
    /// @TODO Optimize it
    int halfOfLength = this->camera.getVisibleMapSize() / 2;

    for (int i(-halfOfLength); i <= halfOfLength; i++) {
        for (int j(-halfOfLength); j <= halfOfLength; j++) {
            // qDebug() << i << " " << j;

            QSizePolicy policy;
            policy.setHorizontalPolicy(QSizePolicy::Expanding);
            policy.setVerticalPolicy(QSizePolicy::Expanding);

            QPushButton* button = new QPushButton();
            button->setSizePolicy(policy);
            button->setFocusPolicy(Qt::FocusPolicy::NoFocus);

            Position currentSymbolPosition = Position(i + camera.getPosition().x, -j + camera.getPosition().y);

            if (!map.isSymbolAt(currentSymbolPosition)) {
                button->setStyleSheet("border-image: url(:res/cell.png);");
            }
            else if (map.getSymbol(currentSymbolPosition) == 'X') {
                button->setStyleSheet("border-image: url(:res/x.png);");
                qDebug() << "Button on the position (" << currentSymbolPosition.x << ";" << currentSymbolPosition.y << ") is X";
            }
            else if (map.getSymbol(currentSymbolPosition) == 'O') {
                button->setStyleSheet("border-image: url(:res/o.png);");
                qDebug() << "Button on the position (" << currentSymbolPosition.x << ";" << currentSymbolPosition.y << ") is O";
            }

            connect(button, &QPushButton::clicked, [currentSymbolPosition, this](){
                if (getCurrentState() == State::InProgress)  {
                    move(currentSymbolPosition);
                }
            });

            qDebug() << i << ";" << j << " -> " << i + halfOfLength << ";" << j + halfOfLength;
            gridLayout->addWidget(button, j + halfOfLength, i + halfOfLength);
            button->show();
        }
    }
}

/**
 * @brief Game::updateCell Updates only one cell.
 * @param position Position othe cell (button) to update.
 */
void Game::updateCell(Position position) {
    QSizePolicy policy;
    policy.setHorizontalPolicy(QSizePolicy::Expanding);
    policy.setVerticalPolicy(QSizePolicy::Expanding);

    QPushButton* button = new QPushButton();
    button->setSizePolicy(policy);
    button->setFocusPolicy(Qt::FocusPolicy::NoFocus);

    connect(button, &QPushButton::clicked, [position, this]() {
        if (getCurrentState() == State::InProgress)  {
            move(position);
        }
    });

    if (!map.isSymbolAt(position)) {
        button->setStyleSheet("border-image: url(:res/cell.png);");
    }
    else if (map.getSymbol(position) == 'X') {
        button->setStyleSheet("border-image: url(:res/x.png);");
    }
    else if (map.getSymbol(position) == 'O') {
        button->setStyleSheet("border-image: url(:res/o.png);");
    }

    qDebug() << position.x - camera.getPosition().x + camera.getVisibleMapSize() / 2 << ":" << camera.getPosition().y - position.y + camera.getVisibleMapSize() / 2;
    gridLayout->addWidget(button, camera.getPosition().y - position.y + camera.getVisibleMapSize() / 2, position.x - camera.getPosition().x + camera.getVisibleMapSize() / 2);
    button->show();
}

/**
 * @brief Game::isCellVisible Checks if the given cell is in the visible area.
 * @param position Position of the cell to check.
 */
bool Game::isCellVisible(Position position)
{
    return position.x >= camera.getPosition().x - camera.getVisibleMapSize() / 2 &&
           position.x <= camera.getPosition().x + camera.getVisibleMapSize() / 2 &&
           position.y >= camera.getPosition().y - camera.getVisibleMapSize() / 2 &&
           position.y <= camera.getPosition().y + camera.getVisibleMapSize() / 2;
}

bool Game::isCellEmpty(Position position)
{
    return map.isSymbolAt(position);
}

void Game::addPlayer(PlayerType playerType) {
    players.push_back(playerType);
}

void Game::setCurrentSymbol(Symbol currentSymbol) {
    this->currentSymbol = currentSymbol;
}

void Game::setCurrentPlayer(int currentPlayer) {
    this->currentPlayer = currentPlayer;
}

void Game::setCurrentState(State state)
{
    this->currentState = state;
}

void Game::setLastSymbolPosition(Position position)
{
    this->lastSymbolPosition = position;
}

void Game::setWinScore(int winScore)
{
    this->winScore = winScore;
}

bool Game::isCurrentPlayerWinner(TicTacToeMap map, Position lastSymbolPosition, int winScore) {
//    qDebug() << "Is (" << lastSymbolPosition.x << lastSymbolPosition.y << ") win for " << map.getSymbol(lastSymbolPosition);
    int score = 0;

    for (int i(-1); i <= 1; i++) {
        for (int j(0); j <= 1; j++) {
            if (i == 0 && j == 0 || i == -1 && j == 0) {
                continue;
            }

            score = 0;
            for (int k(-winScore + 1); k < winScore; k++) {
                int deltaX = i * k;
                int deltaY = j * k;
                Position currentPosition = Position(lastSymbolPosition.x + deltaX, lastSymbolPosition.y + deltaY);

                //qDebug() << "Looking at" << map.getSymbol(currentPosition);
                //qDebug() << "(" << lastSymbolPosition.x << "+" << deltaX << ";" << lastSymbolPosition.y << "+" << deltaY << ")";

                if (map.isSymbolAt(currentPosition) && map.getSymbol(currentPosition) == map.getSymbol(lastSymbolPosition)) {
//                    qDebug() << currentPosition.x << currentPosition.y << " +1";
                    score++;
                }
                else {
//                    qDebug() << currentPosition.x << currentPosition.y << " 0 " << map.isSymbolAt(currentPosition);
                    score = 0;

                    if (currentPosition.x == 0 && currentPosition.y == 2) {
                        if (lastSymbolPosition.x == 0 && lastSymbolPosition.y == 1) {

                        }
                    }
                }

                if (score == winScore) {
//                    qDebug() << "yes";
                    return true;
                }
            }
        }
    }

//    qDebug() << "no";
    return false;
}

/**
 * @brief Game::checkWinner Should be called after setting the symbol, updating its position
 * but before switching the current player and symbol.
 */
bool Game::isCurrentPlayerWinner() {
    return isCurrentPlayerWinner(map, getLastSymbolPosition(), getWinScore());
}

void Game::stop()
{
    setCurrentState(State::End);
    qInfo() << "PLAYER " << getCurrentPlayer() << " WON!";
}

vector<Game::PlayerType> Game::getPlayers()
{
    return this->players;
}

int Game::getCurrentPlayer()
{
    return this->currentPlayer;
}

int Game::getWinScore()
{
    return this->winScore;
}

Game::Symbol Game::getCurrentSymbol()
{
    return this->currentSymbol;
}

/// @TODO Remove
Game::Symbol Game::getSymbol(TicTacToeMap& map, Position position) {
    /// @TODO It is better to ask TicTacToeMap to get symbol!

    if (!map.isSymbolAt(position)) {
        return Game::Symbol::N;
    } else if (map.getSymbol(position) == 'X') {
        return Game::Symbol::X;
    } else {
        return Game::Symbol::O;
    }
}

Game::State Game::getCurrentState()
{
    return this->currentState;
}

Position Game::getLastSymbolPosition()
{
    return this->lastSymbolPosition;
}

void Game::slotButtonClicked(Position position) {
    // setSymbol(x, y, getCurrentSymbol());
    QObject* button = sender();
    //qDebug("CLICKED " + to_string(position.x) + " " + to_string(position.y));
}

char Game::getSwitchedSymbol(char symbol) {
    if (symbol == 'X') {
        return 'O';
    } else {
        return 'X';
    }
}

std::set<std::pair<int, int>> Game::getAvailableMoves() {
    return this->availableMoves;
}

void Game::setAvailableMoves() {
    qDebug() << "AVAILABLE MOVES SIZE BEFORE: " << this->availableMoves.size();
    AI::addAvailableMoves(this->availableMoves, map, winScore, lastSymbolPosition);
    qDebug() << "AVAILABLE MOVES SIZE AFTER: " << this->availableMoves.size();
}
