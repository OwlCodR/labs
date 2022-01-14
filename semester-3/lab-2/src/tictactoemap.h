#ifndef TICTACTOEMAP_H
#define TICTACTOEMAP_H

#include "position.h"

#include <map>
#include <vector>

class TicTacToeMap
{
public:
    TicTacToeMap();

    void setSymbol(Position position, char symbol);
    char getSymbol(Position position);

    int getSize();
private:
    std::map<Position, char> map;
};

#endif // TICTACTOEMAP_H
