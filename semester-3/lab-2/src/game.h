#ifndef GAME_H
#define GAME_H

#include <QGridLayout>
#include <QObject>
#include <map>
#include <vector>
#include "camera.h"
#include "position.h"
#include "tictactoemap.h"

using namespace std;

/**
 * @brief The Game class that contains the logic of the Tic Tac Toe
 */
class Game : public QObject {

    Q_OBJECT

public:
    enum PlayerType {Human, AI};

    Game();
    void start(int firstPlayerIndex, char firstPlayerSymbol);
    void move(Position position, char symbol);
    void updateMap();

    void setVisibleMapSize(int visibleMapSize);
    void addPlayer(PlayerType playerType);
    void setCurrentSymbol(char currentSymbol);
    void setCurrentPlayer(int currentPlayer);

    vector<PlayerType> getPlayers();
    int getCurrentPlayer();
    char getCurrentSymbol();

    int getVisibleMapSize();
    Position getCenterPosition();

    QGridLayout* gridLayout;
private:
    vector<PlayerType> players;
    int currentPlayer; // Index int the vector<PlayerType> players
    char currentSymbol;

    Camera camera;
    TicTacToeMap map;

    void setSymbol(Position position, char symbol);

    void switchCurrentPlayer();
    void switchCurrentSymbol();
    void checkWinner();

    void stop();
    void stop(int winnerIndex);
public slots:
    void slotButtonClicked();
signals:
    void valueChanged(int newValue);
};

#endif // GAME_H
