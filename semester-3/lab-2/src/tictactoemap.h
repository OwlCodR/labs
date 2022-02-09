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

    void clear();

    void setSymbol(Position position, char symbol);
    void removeSymbol(Position position);

    char getSymbol(Position position);
    bool isSymbolAt(Position position);

    int getSize();
private:
    std::map<std::pair<int, int>, char> map;
    // @TODO Change to std::map<Position, char>
};

#endif // TICTACTOEMAP_H
