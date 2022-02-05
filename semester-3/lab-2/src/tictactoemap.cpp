#include "tictactoemap.h"

#include <QDebug>

TicTacToeMap::TicTacToeMap() {

}

void TicTacToeMap::setSymbol(Position position, char symbol) {
    this->map[std::make_pair(position.x, position.y)] = symbol;

    // qInfo() << "Sets symbol " << symbol << " on " << position.x << ":" << position.y;
}

void TicTacToeMap::removeSymbol(Position position) {
    this->map.erase(std::make_pair(position.x, position.y));
}

char TicTacToeMap::getSymbol(Position position) {
    return this->map.at(std::make_pair(position.x, position.y));
}

bool TicTacToeMap::isSymbolAt(Position position) {
    return this->map.find(std::make_pair(position.x, position.y)) != map.end();
}

int TicTacToeMap::getSize() {
    return this->map.size();
}
