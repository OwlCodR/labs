#include "tictactoemap.h"

TicTacToeMap::TicTacToeMap()
{

}

void TicTacToeMap::setSymbol(Position position, char symbol)
{
    this->map[position.x][position.y] = symbol;
}

char TicTacToeMap::getSymbol(Position position)
{
    return this->map[position.x][position.y];
}

int TicTacToeMap::getSize()
{
    return this->map.size();
}
