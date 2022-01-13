#ifndef TICTACTOEMAP_H
#define TICTACTOEMAP_H

#include "position.h"

#include <vector>

class TicTacToeMap
{
public:
    TicTacToeMap();

    char setSymbol(Position position, char symbol);
    char getSymbol(Position position);

    int getSize();
private:
    std::vector<std::vector<int>> map;
};

#endif // TICTACTOEMAP_H
