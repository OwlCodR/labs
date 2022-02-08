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
    enum State {Waiting, InProgress, End};
    enum Symbol {X, O, N}; // N - NULL (Empty)

    Game();
    void start(int firstPlayerIndex, Symbol firstPlayerSymbol);
    void move(Position position);
    void updateMap();
    void updateCell(Position position);
    bool isCellVisible(Position position);
    bool isCellEmpty(Position position);

    void addPlayer(PlayerType playerType);
    void setCurrentSymbol(Symbol currentSymbol);
    void setCurrentPlayer(int currentPlayer);
    void setCurrentState(State currentState);
    void setLastSymbolPosition(Position position);
    void addAvailableMoves();
    void setWinScore(int winScore);

    vector<PlayerType> getPlayers();
    int getCurrentPlayer();
    int getWinScore();
    Symbol getCurrentSymbol();
    State getCurrentState();
    Position getLastSymbolPosition();
    std::set<std::pair<int, int>> getAvailableMoves();
    static char getSwitchedSymbol(char symbol);
    static bool isCurrentPlayerWinner(TicTacToeMap map, Position lastSymbolPosition, int winScore);
    static Symbol getSymbol(TicTacToeMap& map, Position position);

    QGridLayout* gridLayout;
    Camera camera;
private:
    vector<PlayerType> players;
    int currentPlayer; // Index int the vector<PlayerType> players
    int winScore; // Count of symbols to set inline to win
    Symbol currentSymbol;
    State currentState;
    Position lastSymbolPosition;

    TicTacToeMap map;
    std::set<std::pair<int, int>> availableMoves;

    void setSymbol(Position position, Symbol symbol);

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
