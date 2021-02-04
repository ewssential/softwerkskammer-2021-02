#ifndef MARS_ROVER_H
#define MARS_ROVER_H

#include <string>


enum class Direction {
    East,
    North,
    West,
    South
};


enum class Rotation {
    Left = 'l',
    Right = 'r'
};


enum class Movement {
    Forward = 'f',
    Backward = 'b'
};


class Point {
    int _x;
    int _y;

public:
    Point() = default;
    Point(int x, int y);

    bool operator==(const Point &rhs) const;
    bool operator!=(const Point &rhs) const;

    [[nodiscard]] int getX() const;
    [[nodiscard]] int getY() const;
};


class MarsRover {
public:
    MarsRover(const Point &position, Direction direction);
    [[nodiscard]] const Point &getPosition() const;
    [[nodiscard]] Direction getDirection() const;
    MarsRover &execute(const std::string &commands);

private:
    void move(Movement movement);
    void rotateLeft();
    void rotateRight();

    Point _position;
    Direction _direction;
};


#endif //MARS_ROVER_H
