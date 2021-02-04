#include <stdexcept>
#include "mars_rover.h"


Point::Point(int x, int y) : _x(x), _y(y) {
}


int Point::getX() const {
    return _x;
}


int Point::getY() const {
    return _y;
}


bool Point::operator==(const Point &rhs) const {
    return _x == rhs._x &&
           _y == rhs._y;
}


bool Point::operator!=(const Point &rhs) const {
    return !(rhs == *this);
}


Direction getNextDirection(Direction direction) {
    switch (direction) {
    case Direction::East:
        return Direction::North;
    case Direction::North:
        return Direction::West;
    case Direction::West:
        return Direction::South;
    case Direction::South:
        return Direction::East;
    default:
        throw std::logic_error(
                std::string("unexpected direction value ") + std::to_string(static_cast<int>(direction)));
    }
}


Direction getPreviousDirection(Direction direction) {
    switch (direction) {
    case Direction::East:
        return Direction::South;
    case Direction::North:
        return Direction::East;
    case Direction::West:
        return Direction::North;
    case Direction::South:
        return Direction::West;
    default:
        throw std::logic_error(
                std::string("unexpected direction value ") + std::to_string(static_cast<int>(direction)));
    }
}


MarsRover::MarsRover(const Point &position, Direction direction) : _position(position), _direction(direction) {}


const Point &MarsRover::getPosition() const {
    return _position;
}


Direction MarsRover::getDirection() const {
    return _direction;
}


MarsRover &MarsRover::execute(const std::string &commands) {
    for (auto c : commands) {
        switch (c) {
        case static_cast<decltype(c)>(Rotation::Left):
            rotateLeft();
            break;
        case static_cast<decltype(c)>(Rotation::Right):
            rotateRight();
            break;
        case static_cast<decltype(c)>(Movement::Forward):
        case static_cast<decltype(c)>(Movement::Backward):
            move(static_cast<Movement>(c));
            break;
        default:
            throw std::logic_error(
                    std::string("unknown command '") + c + "'");
        }
    }
    return *this;
}


void MarsRover::move(Movement movement) {

    auto step = movement == Movement::Forward ? 1 : -1;

    switch (_direction) {
    case Direction::East:
        _position = Point(_position.getX() + step, _position.getY());
        break;
    case Direction::North:
        _position = Point(_position.getX(), _position.getY() - step);
        break;
    case Direction::West:
        _position = Point(_position.getX() - step, _position.getY());
        break;
    case Direction::South:
        _position = Point(_position.getX(), _position.getY() + step);
        break;
    default:
        throw std::logic_error(
                std::string("unexpected direction value ") + std::to_string(static_cast<int>(_direction)));
    }
}


void MarsRover::rotateLeft() {
    _direction = getNextDirection(_direction);
}


void MarsRover::rotateRight() {
    _direction = getPreviousDirection(_direction);
}

