#ifndef MARS_ROVER_TEST_SUPPORT_H
#define MARS_ROVER_TEST_SUPPORT_H

#include "mars_rover.h"

std::ostream &operator<<(std::ostream &os, const Point &point);
std::ostream &operator<<(std::ostream &os, Direction direction);
std::ostream &operator<<(std::ostream &os, Rotation rotation);
std::ostream &operator<<(std::ostream &os, Movement movement);

#endif //MARS_ROVER_TEST_SUPPORT_H
