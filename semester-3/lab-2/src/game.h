#ifndef GAME_H
#define GAME_H

#include <QGridLayout>
#include <QObject>
#include <map>
#include <vector>
#include "camera.h"
#include "position.h"
#include "ai.h"
#include "tictactoemap.h"

using namespace std;

/**
 * @brief The Game class that contains the logic of the Tic Tac Toe
 */
class Game : public QObject {

    Q_OBJECT

public:
    enum PlayerType {Human, AI};
    enum GameState {Waiting, InProgress, End};

    Game();
    void start(int firstPlayerIndex, char firstPlayerSymbol);
    void move(Position position);
    void updateMap();
    void updateCell(Position position);
    bool isCellVisible(Position position);
    bool isCellEmpty(Position position);

    void addPlayer(PlayerType playerType);
    void setCurrentSymbol(char currentSymbol);
    void setCurrentPlayer(int currentPlayer);
    void setCurrentState(GameState currentState);
    void setLastSymbolPosition(Position position);
    void setWinScore(int winScore);

    vector<PlayerType> getPlayers();
    int getCurrentPlayer();
    int getWinScore();
    char getCurrentSymbol();
    GameState getCurrentState();
    Position getLastSymbolPosition();

    QGridLayout* gridLayout;
    Camera camera;
private:
    vector<PlayerType> players;
    int currentPlayer; // Index int the vector<PlayerType> players
    int winScore; // Count of symbols to set inline to win
    char currentSymbol;
    GameState currentState;
    Position lastSymbolPosition;

    TicTacToeMap map;

    void setSymbol(Position position, char symbol);

    void switchCurrentPlayer();
    void switchCurrentSymbol();
    bool isCurrentPlayerWinner();

    void stop();
public slots:
    void slotButtonClicked(Position position);
signals:
    void valueChanged(int newValue);
};

#endif // GAME_H
