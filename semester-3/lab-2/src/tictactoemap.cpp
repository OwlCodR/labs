#include "tictactoemap.h"

TicTacToeMap::TicTacToeMap()
{

}

void TicTacToeMap::setSymbol(Position position, char symbol)
{
    this->map[position] = symbol;
}

char TicTacToeMap::getSymbol(Position position)
{
    return this->map[position];
}

int TicTacToeMap::getSize()
{
    return this->map.size();
}
