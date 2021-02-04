#include "gtest/gtest.h"
#include "mars_rover.h"
#include "mars_rover.test.support.h"


// https://github.com/google/googletest/blob/master/docs/advanced.md


TEST(MarsRoverTest, ConstructorShouldNotThrow) {
    EXPECT_NO_THROW(MarsRover(Point{0, 0}, Direction::East));
}


TEST(MarsRoverTest, ConstructorShouldInitializeStartingPoint) {
    EXPECT_EQ(MarsRover(Point{1, 4}, Direction::East).getPosition(), (Point{1, 4}));
}


TEST(MarsRoverTest, ConstructorShouldInitializeDirection) {
    EXPECT_EQ(MarsRover(Point{2, 2}, Direction::West).getDirection(), Direction::West);
}


struct RotationTestData {
    Direction initialDirection;
    Rotation rotation;
    Direction expectedDirection;

    friend std::ostream &operator<<(std::ostream &os, const RotationTestData &obj) {
        return os << "initialDirection: " << obj.initialDirection << ", rotation: " << obj.rotation
                  << ", expectedDirection: " << obj.expectedDirection;
    }
};


struct RotationTest : public testing::TestWithParam<RotationTestData> {
    Direction initialDirection;
    Rotation rotation;
    Direction expectedDirection;

    RotationTest() {
        initialDirection = GetParam().initialDirection;
        rotation = GetParam().rotation;
        expectedDirection = GetParam().expectedDirection;
    }
};


TEST_P(RotationTest, TestRotation) {
    EXPECT_EQ(MarsRover(Point{0, 0}, initialDirection).execute(
            std::string(1, static_cast<std::string::value_type>(rotation))).getDirection(), expectedDirection);
}


INSTANTIATE_TEST_SUITE_P(RotationTestSuite, RotationTest,
                         testing::Values(RotationTestData{Direction::East, Rotation::Left, Direction::North},
                                         RotationTestData{Direction::North, Rotation::Left, Direction::West},
                                         RotationTestData{Direction::West, Rotation::Left, Direction::South},
                                         RotationTestData{Direction::South, Rotation::Left, Direction::East},
                                         RotationTestData{Direction::East, Rotation::Right, Direction::South},
                                         RotationTestData{Direction::North, Rotation::Right, Direction::East},
                                         RotationTestData{Direction::West, Rotation::Right, Direction::North},
                                         RotationTestData{Direction::South, Rotation::Right, Direction::West}));


struct MovementTestData {
    Point initialPosition;
    Direction initialDirection;
    Movement movement;
    Point expectedPosition;

    friend std::ostream &operator<<(std::ostream &os, const MovementTestData &obj) {
        return os << "initialPosition: " << obj.initialPosition << ", initialDirection: " << obj.initialDirection
                  << ", movement: " << obj.movement << ", expectedPosition: " << obj.expectedPosition;
    }
};


struct MovementTest : public testing::TestWithParam<MovementTestData> {
    Point initialPosition;
    Direction initialDirection;
    Movement movement;
    Point expectedPosition;

    MovementTest() {
        initialPosition = GetParam().initialPosition;
        initialDirection = GetParam().initialDirection;
        movement = GetParam().movement;
        expectedPosition = GetParam().expectedPosition;
    }
};


TEST_P(MovementTest, TestMovement) {
    EXPECT_EQ(MarsRover(initialPosition, initialDirection).execute(
            std::string(1, static_cast<std::string::value_type>(movement))).getPosition(), expectedPosition);
}


INSTANTIATE_TEST_SUITE_P(MovementTestSuite, MovementTest,
                         testing::Values(MovementTestData{Point{3, 3}, Direction::East, Movement::Forward, Point{4, 3}},
                                         MovementTestData{Point{3, 3}, Direction::North, Movement::Forward,
                                                          Point{3, 2}},
                                         MovementTestData{Point{3, 3}, Direction::West, Movement::Forward, Point{2, 3}},
                                         MovementTestData{Point{3, 3}, Direction::South, Movement::Forward,
                                                          Point{3, 4}},
                                         MovementTestData{Point{3, 3}, Direction::East, Movement::Backward,
                                                          Point{2, 3}},
                                         MovementTestData{Point{3, 3}, Direction::North, Movement::Backward,
                                                          Point{3, 4}},
                                         MovementTestData{Point{3, 3}, Direction::West, Movement::Backward,
                                                          Point{4, 3}},
                                         MovementTestData{Point{3, 3}, Direction::South, Movement::Backward,
                                                          Point{3, 2}}));


TEST(PointTest, ContructorFromCoordinatesShouldNotThrow) {
    EXPECT_NO_THROW((Point{0, 0}));
}


TEST(PointTest, ContructorFromCoordinatesShouldInitializeX) {
    EXPECT_EQ((Point{4, 1}).getX(), 4);
}


TEST(PointTest, ContructorFromCoordinatesShouldInitializeY) {
    EXPECT_EQ((Point{0, 3}).getY(), 3);
}


TEST(PointTest, EqualityOperator) {
    EXPECT_EQ((Point{4, 1}), (Point{4, 1}));
}


TEST(PointTest, InequalityOperator) {
    EXPECT_NE((Point{1, 4}), (Point{4, 1}));
}

