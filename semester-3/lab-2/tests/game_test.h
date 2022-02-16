#ifndef GAME_TEST_H
#define GAME_TEST_H

#include <QtTest/QtTest>

#include <src/game.h>
#include <src/tictactoemap.h>

class GameTest : public QObject
{
    Q_OBJECT

public:
    virtual ~GameTest() {};

private:
    bool myCondition()
    {
        return true;
    }

private slots:
    void initTestCase()
    {
        qDebug("Called before everything else.");
    }

    void isCurrentPlayerWinnerTest() {
        Position lastSymbolPosition(Position(0, 2));
        int winScore = 3;
        TicTacToeMap map;

        // Test 1

        map.setSymbol(Position(0, 0), 'X');
        map.setSymbol(Position(0, 1), 'X');
        map.setSymbol(Position(0, 2), 'X');

        QVERIFY(Game::isCurrentPlayerWinner(map, lastSymbolPosition, winScore) == true);

        // Test 2

        map.clear();

        map.setSymbol(Position(0,0), 'X');
        map.setSymbol(Position(0,-1), 'O');
        map.setSymbol(Position(-1,0), 'X');
        map.setSymbol(Position(-1,-1), 'O');
        map.setSymbol(Position(-2,0), 'X');
        map.setSymbol(Position(-2,-1), 'O');
        map.setSymbol(Position(-3,0), 'X');

        QVERIFY(Game::isCurrentPlayerWinner(map, lastSymbolPosition, winScore) == true);

        // Test 3

        map.clear();

        map.setSymbol(Position(0,0), 'X');
        map.setSymbol(Position(-1,-1), 'O');
        map.setSymbol(Position(-1,1), 'X');
        map.setSymbol(Position(-2,0), 'O');
        map.setSymbol(Position(1,-1), 'X');
        map.setSymbol(Position(0,-2), 'O');
        map.setSymbol(Position(2,-2), 'X');

        QVERIFY(Game::isCurrentPlayerWinner(map, lastSymbolPosition, winScore) == true);

        // Test 4

        map.clear();

        map.setSymbol(Position(0,0), 'X');
        map.setSymbol(Position(-1,0), 'O');
        map.setSymbol(Position(-2,0), 'X');
        map.setSymbol(Position(-3,0), 'O');
        map.setSymbol(Position(-4,0), 'X');
        map.setSymbol(Position(-4,1), 'O');
        map.setSymbol(Position(-3,1), 'X');
        map.setSymbol(Position(-2,1), 'O');
        map.setSymbol(Position(-1,1), 'X');
        map.setSymbol(Position(0,1), 'O');
        map.setSymbol(Position(0,2), 'X');
        map.setSymbol(Position(1,1), 'O');
        map.setSymbol(Position(1,3), 'X');

        QVERIFY(Game::isCurrentPlayerWinner(map, lastSymbolPosition, winScore) == true);
    }

    void myFirstTest()
    {
        QVERIFY(true); // check that a condition is satisfied
        QCOMPARE(1, 1); // compare two values
    }

    void mySecondTest()
    {
        QVERIFY(myCondition());
        QVERIFY(1 != 2);
    }

    void cleanupTestCase()
    {
        qDebug("Called after myFirstTest and mySecondTest.");
    }
};

#endif
