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
void Game::move(Position position)
{
    if (getCurrentState() != Game::GameState::InProgress)
        return;

    setSymbol(position, getCurrentSymbol());
    AI::updateAvailableMoves(map, winScore, position);

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
        move(AI::getMovePosition(map, camera, winScore));
    }
}

/**
 * @brief Game::setSymbol Sets symbol to the TicTacToeMap and updates lastSymbolPosition.
 * @param Position Position of the symbol.
 * @param symbol Char 'X' or 'O'.
 */
void Game::setSymbol(Position position, char symbol)
{
    if (map.getSymbol(position)) {
        qWarning() << "[Warning] There is already another symbol!";
        return;
    }

    this->map.setSymbol(position, symbol);
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
    if (currentSymbol == 'X') {
        currentSymbol = 'O';
    } else {
        currentSymbol = 'X';
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
            if (map.getSymbol(currentSymbolPosition) == 'X') {
                button->setStyleSheet("border-image: url(:res/x.png);");
                qDebug() << "Button on the position (" << currentSymbolPosition.x << ";" << currentSymbolPosition.y << ") is X";
            } else if (map.getSymbol(currentSymbolPosition) == 'O') {
                button->setStyleSheet("border-image: url(:res/o.png);");
                qDebug() << "Button on the position (" << currentSymbolPosition.x << ";" << currentSymbolPosition.y << ") is O";
            } else {
                button->setStyleSheet("border-image: url(:res/cell.png);");
            }

            connect(button, &QPushButton::clicked, [currentSymbolPosition, this](){
                if (getCurrentState() == Game::GameState::InProgress)  {
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
        if (getCurrentState() == Game::GameState::InProgress)  {
            move(position);
        }
    });

    if (map.getSymbol(position) == 'X') {
        button->setStyleSheet("border-image: url(:res/x.png);");
    } else if (map.getSymbol(position) == 'O') {
        button->setStyleSheet("border-image: url(:res/o.png);");
    } else {
        button->setStyleSheet("border-image: url(:res/cell.png);");
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
    return map.getSymbol(position);
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

void Game::setCurrentState(GameState state)
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

/**
 * @brief Game::checkWinner Should be called after setting the symbol, updating its position
 * but before switching the current player and symbol.
 */
bool Game::isCurrentPlayerWinner()
{
    int score = 0;

    Position position = getLastSymbolPosition();
    // qDebug() << "Position" << position.x << ";" << position.y;

    for (int i(0); i <= 1; i++) {
        for (int j(-1); j <= 1; j++) {
            if ((i == 0 && j == 0) || (i == 0 && j == -1)) {
                continue;
            }

            score = 0;
            for (int k(-getWinScore() + 1); k < getWinScore(); k++) {
                if (map.getSymbol(Position(position.x + i * k, position.y + j * k)) == getCurrentSymbol())
                    score++;
                else
                    score = 0;

                // qDebug() << "Checking" << position.x + i * k << ";" << position.y + j * k << " Score:" << score;

                if (score == getWinScore())
                    return true;
            }
        }
    }

    return false;
}

void Game::stop()
{
    setCurrentState(Game::GameState::End);
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

char Game::getCurrentSymbol()
{
    return this->currentSymbol;
}

Game::GameState Game::getCurrentState()
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
