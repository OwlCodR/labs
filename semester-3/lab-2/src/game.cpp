#include "game.h"

#include <QPushButton>

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
    Position mapIndexes = this->camera.toMapPos(this->map, position);
    this->map.setSymbol(mapIndexes, symbol);
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

void Game::updateMap()
{
    int halfOfLength = (getVisibleMapSize() - 1) / 2;
    int XLeftCorner = getCenterPosition().x - halfOfLength;
    int YUpCorner = getCenterPosition().y - halfOfLength;

    for (int i(XLeftCorner); i < getVisibleMapSize(); i++) {
        for (int k(YUpCorner); k < getVisibleMapSize(); k++) {
            QSizePolicy policy;
            policy.setHorizontalPolicy(QSizePolicy::Expanding);
            policy.setVerticalPolicy(QSizePolicy::Expanding);

            QPushButton* button = new QPushButton();
            button->setSizePolicy(policy);
            button->setFocusPolicy(Qt::FocusPolicy::NoFocus);
            connect(button, SIGNAL(clicked()), this, SLOT(onButtonClicked()));


            switch(gameMap[i][k]) {
                case 'X': {
                    button->setStyleSheet("border-image: url(:res/x.png);");
                    break;
                }
                case 'O': {
                    button->setStyleSheet("border-image: url(:res/o.png);");
                    break;
                }
                case ' ': {
                    button->setStyleSheet("border-image: url(:res/cell.png);");
                    break;
                }
            }

            gameMap[i][k];
            gridLayout->addWidget(button, i - XLeftCorner, k - YUpCorner);
            button->show();
        }
    }

//    QApplication app(argc,argv);
//    QWidget *wid=new QWidget();
//    QVBoxLayout *layout=new QVBoxLayout();
//    for (int i = 0; i < 10; ++i){
//       QPushButton *button = new QPushButton();
//        button->setText(QString::number(i));
//        //QObject::connect(button, SIGNAL(clicked(bool)), wid, SLOT(onClicked(bool))); <-- THERE IS NO SUCH SLOT IN QWIDGET!
//        layout->addWidget(button);
//        button->show();
//    }
//    wid->setLayout(layout); // Add the layout to widget!
//    wid->show();
//    return app.exec();
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

void Game::updateCurrentPlayer()
{

}

void Game::updateCurrentSymbol()
{

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

void Game::setCenterPosition(Position centerPosition)
{
    this->centerPosition = centerPosition;
}

void Game::setVisibleMapSize(int visibleMapSize)
{
    this->visibleMapSize = visibleMapSize;
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

int Game::getVisibleMapSize()
{
    return this->visibleMapSize;
}

Position Game::getCenterPosition()
{
    return this->centerPosition;
}

void Game::slotButtonClicked() {
    // setSymbol(x, y, getCurrentSymbol());
    qDebug("CLICKED");
}
