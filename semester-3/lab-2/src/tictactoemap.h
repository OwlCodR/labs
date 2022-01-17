#ifndef TICTACTOEMAP_H
#define TICTACTOEMAP_H

#include "position.h"

#include <map>
#include <set>
#include <vector>

class TicTacToeMap
{
public:
    TicTacToeMap();

    void setSymbol(Position position, char symbol);
    char getSymbol(Position position);

    std::set<Position> getSymbolsPositions();

    int getSize();
private:
    std::set<Position> symbolsPositions;
    std::map<std::pair<int, int>, char> map;
    // @TODO Change to std::map<Position, char>
};

#endif // TICTACTOEMAP_H
