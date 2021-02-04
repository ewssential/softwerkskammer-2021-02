#include "mars_rover.test.support.h"
#include "gtest/gtest.h"


std::ostream &operator<<(std::ostream &os, const Point &point) {
    return os << "(" << point.getX() << ", " << point.getY() << ")";
}


auto toString(Direction direction) {
    switch (direction) {
    case Direction::East:
        return "East";
    case Direction::North:
        return "North";
    case Direction::West:
        return "West";
    case Direction::South:
        return "South";
    default:
        throw std::logic_error(
                std::string("unexpected direction value ") + std::to_string(static_cast<int>(direction)));
    }
}


std::ostream &operator<<(std::ostream &os, Direction direction) {
    return os << toString(direction);
}


auto toString(Rotation rotation) {
    switch (rotation) {
    case Rotation::Left:
        return "Left";
    case Rotation::Right:
        return "Right";
    default:
        throw std::logic_error(
                std::string("unexpected rotation value ") + std::to_string(static_cast<int>(rotation)));
    }
}


std::ostream &operator<<(std::ostream &os, Rotation rotation) {
    return os << toString(rotation);
}


auto toString(Movement movement) {
    switch (movement) {
    case Movement::Forward:
        return "Forward";
    case Movement::Backward:
        return "Backward";
    default:
        throw std::logic_error(
                std::string("unexpected movement value ") + std::to_string(static_cast<int>(movement)));
    }
}


std::ostream &operator<<(std::ostream &os, Movement movement) {
    return os << toString(movement);
}

