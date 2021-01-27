using System.Collections.Generic;
using Xunit;

namespace MarsRoverKata
{
    public class MarsRoverTest
    {
        [Theory]
        [InlineData(Direction.North)]
        [InlineData(Direction.East)]
        [InlineData(Direction.South)]
        [InlineData(Direction.West)]
        public void Constructor_Direction_Test(Direction direction)
        {
            Assert.Equal(direction, new MarsRover(new Position(23, 42), direction).Direction);
        }

        [Fact]
        public void Constructor_PositionX_Test()
        {
            Assert.Equal(23, new MarsRover(new Position(23, 42), Direction.North).X);
        }

        [Fact]
        public void Constructor_PositionY_Test()
        {
            Assert.Equal(42, new MarsRover(new Position(23, 42), Direction.North).Y);
        }
    }

    public class MarsRoverRotationTest
    {
        private static readonly Position StartPosition = new(3, 3);

        [Theory]
        [InlineData(Direction.North, Direction.East)]
        [InlineData(Direction.East, Direction.South)]
        [InlineData(Direction.South, Direction.West)]
        [InlineData(Direction.West, Direction.North)]
        public void Rotate_Right_Test(Direction initialDirection, Direction expectedDirection)
        {
            var rover = new MarsRover(StartPosition, initialDirection);
            Assert.Equal(expectedDirection, rover.Execute(new[] {'r'}).Direction);
        }

        [Theory]
        [InlineData(Direction.North, Direction.West)]
        [InlineData(Direction.West, Direction.South)]
        [InlineData(Direction.South, Direction.East)]
        [InlineData(Direction.East, Direction.North)]
        public void Rotate_Left_Test(Direction initialDirection, Direction expectedDirection)
        {
            var rover = new MarsRover(StartPosition, initialDirection);
            Assert.Equal(expectedDirection, rover.Execute(new[] {'l'}).Direction);
        }
    }

    public class MarsRoverMovementTest
    {
        private static readonly Position StartPosition = new(3, 3);

        public static List<object[]> Move_Forward_Test_Data()
        {
            return new()
            {
                new object[] {Direction.North, new Position(StartPosition.X, StartPosition.Y - 1)},
                new object[] {Direction.East, new Position(StartPosition.X + 1, StartPosition.Y)},
                new object[] {Direction.South, new Position(StartPosition.X, StartPosition.Y + 1)},
                new object[] {Direction.West, new Position(StartPosition.X - 1, StartPosition.Y)}
            };
        }

        [Theory]
        [MemberData(nameof(Move_Forward_Test_Data))]
        public void Move_Forward_Test(Direction direction, Position expectedPosition)
        {
            var rover = new MarsRover(StartPosition, direction);
            rover.Execute(new[] {'f'});
            Assert.Equal(expectedPosition, new Position(rover.X, rover.Y));
        }

        [Theory]
        [MemberData(nameof(Move_Backward_Test_Data))]
        public void Move_Backward_Test(Direction direction, Position expectedPosition)
        {
            var rover = new MarsRover(StartPosition, direction);
            rover.Execute(new[] {'b'});
            Assert.Equal(expectedPosition, new Position(rover.X, rover.Y));
        }

        public static List<object[]> Move_Backward_Test_Data()
        {
            return new()
            {
                new object[] {Direction.North, new Position(StartPosition.X, StartPosition.Y + 1)},
                new object[] {Direction.East, new Position(StartPosition.X - 1, StartPosition.Y)},
                new object[] {Direction.South, new Position(StartPosition.X, StartPosition.Y - 1)},
                new object[] {Direction.West, new Position(StartPosition.X + 1, StartPosition.Y)}
            };
        }
    }
}