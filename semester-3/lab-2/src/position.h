#ifndef POSITION_H
#define POSITION_H

class Position {
public:
    int x, y;

    Position(){};
    Position(int x, int y) {
        this->x = x;
        this->y = y;
    }

    Position(const Position& position) {
        this->x = position.x;
        this->y = position.y;
    }

    Position operator+(Position position) {
        return Position(x + position.x, y + position.y);
    }

    Position operator-(Position position) {
        return Position(x - position.x, y - position.y);
    }

    Position& operator=(Position position) {
        x = position.x;
        y = position.y;
        return *this;
    }
};

#endif // POSITION_H
