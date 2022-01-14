#include "tictactoemap.h"

#include <QDebug>

TicTacToeMap::TicTacToeMap()
{

}

void TicTacToeMap::setSymbol(Position position, char symbol)
{
    this->map[std::make_pair(position.x, position.y)] = symbol;
    qInfo() << "Sets symbol " << symbol << " on " << position.x << ":" << position.y;
}

char TicTacToeMap::getSymbol(Position position)
{
    return this->map[std::make_pair(position.x, position.y)];
}

int TicTacToeMap::getSize()
{
    return this->map.size();
}
