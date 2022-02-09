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

/**
 * @brief The Game class that contains the logic of the Tic Tac Toe
 */
class Game : public QObject {

    Q_OBJECT

public:
    typedef std::set<std::pair<int, int>> Set;

    enum PlayerType {Human, AI};
    enum State {Waiting, InProgress, End};
    enum Symbol {X, O, N}; // N - NULL (Empty)

    Game();

    void start(int firstPlayerIndex, Symbol firstPlayerSymbol);
    void restart();

    void move(Position position);

    void updateMap();
    void updateCell(Position position);

    bool isCellVisible(Position position);
    bool isCellEmpty(Position position);

    void setGridLayout(QGridLayout* gridLayout);
    void setLastSymbolPosition(Position position);
    void setCurrentSymbol(Symbol currentSymbol);
    void setCurrentState(State currentState);
    void setCurrentPlayer(int currentPlayer);
    void setWinScore(int winScore);

    void addPlayer(PlayerType playerType);
    void addAvailableMoves();

    Position getLastSymbolPosition();
    std::vector<PlayerType> getPlayers();
    QGridLayout* getGridLayout();
    Symbol getCurrentSymbol();
    State getCurrentState();
    Camera& getCamera();
    Set getAvailableMoves();

    int getCurrentPlayer();
    int getWinScore();

    void clearGridLayout();

    static char getSwitchedSymbol(char symbol);
    static bool isCurrentPlayerWinner(TicTacToeMap map, Position lastSymbolPosition, int winScore);
    static Symbol getSymbol(TicTacToeMap& map, Position position);
private:
    Position lastSymbolPosition;
    std::vector<PlayerType> players;
    QGridLayout* gridLayout;
    Symbol currentSymbol;
    State currentState;
    Camera camera;

    int currentPlayer; // Index int the vector<PlayerType> players
    int winScore; // Count of symbols to set inline to win

    TicTacToeMap map;
    Set availableMoves;

    void setSymbol(Position position, Symbol symbol);

    void switchCurrentPlayer();
    void switchCurrentSymbol();
    bool isCurrentPlayerWinner();

    void stop();
signals:
    void valueChanged(int newValue);
};

#endif // GAME_H
