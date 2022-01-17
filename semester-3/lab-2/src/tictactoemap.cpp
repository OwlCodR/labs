#include "tictactoemap.h"

#include <QDebug>

TicTacToeMap::TicTacToeMap() {

}

void TicTacToeMap::setSymbol(Position position, char symbol) {
    this->map[std::make_pair(position.x, position.y)] = symbol;
    symbolsPositions.insert(position);

    qInfo() << "Sets symbol " << symbol << " on " << position.x << ":" << position.y;
}

char TicTacToeMap::getSymbol(Position position) {
    return this->map[std::make_pair(position.x, position.y)];
}

std::set<Position> TicTacToeMap::getSymbolsPositions() {
    return this->symbolsPositions;
}

int TicTacToeMap::getSize() {
    return this->map.size();
}
