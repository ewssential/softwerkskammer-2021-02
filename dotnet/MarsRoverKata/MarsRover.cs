using System;
using System.Collections.Generic;

namespace MarsRoverKata
{
    public class MarsRover
    {
        public static class Movement
        {
            public const char Forward = 'f';
            public const char Backward = 'b';
        }
        
        private Position _position;
        private Direction _direction;

        public Position Position => _position;

        public Direction Direction => _direction;

        public MarsRover(Position position, Direction direction)
        {
            _position = position;
            _direction = direction;
        }

        public MarsRover Execute(IEnumerable<char> commands)
        {
            foreach (var command in commands)
            {
                switch (command)
                {
                    case 'r':
                        _direction = _direction.Next();
                        break;
                    case 'l':
                        _direction = _direction.Previous();
                        break;
                    case Movement.Forward:
                    case Movement.Backward:
                        Move(command);
                        break;
                    default:
                        throw new ArgumentException($"invalid command {command} provided");
                }
            }

            return this;
        }

        private void Move(char movement)
        {
            var step = movement == Movement.Forward ? 1 : -1;

            _position = _direction switch
            {
                Direction.North => new Position(_position.X, _position.Y - step),
                Direction.East => new Position(_position.X + step, _position.Y),
                Direction.South => new Position(_position.X, _position.Y + step),
                Direction.West => new Position(_position.X - step, _position.Y),
                _ => throw new InvalidOperationException($"unexpected direction value {_direction} encountered")
            };
        }
    }

    public static class DirectionExtensions
    {
        public static Direction Next(this Direction direction)
        {
            return direction switch
            {
                Direction.North => Direction.East,
                Direction.East => Direction.South,
                Direction.South => Direction.West,
                Direction.West => Direction.North,
                _ => throw new ArgumentException($"unexpected direction value {direction} provided")
            };
        }
        
        public static Direction Previous(this Direction direction)
        {
            return direction switch
            {
                Direction.North => Direction.West,
                Direction.West => Direction.South,
                Direction.South => Direction.East,
                Direction.East => Direction.North,
                _ => throw new ArgumentException($"unexpected direction value {direction} provided")
            };
        }
    }

    public enum Direction
    {
        North,
        East,
        South,
        West
    }

    public readonly struct Position
    {
        public int X { get; }

        public int Y { get; }

        public Position(int x, int y)
        {
            X = x;
            Y = y;
        }

        private bool Equals(Position other)
        {
            return X == other.X && Y == other.Y;
        }

        public override string ToString()
        {
            return $"{{ x = {X}, x = {Y} }}";
        }

        public override bool Equals(object obj)
        {
            return obj is Position other && Equals(other);
        }

        public override int GetHashCode()
        {
            return HashCode.Combine(X, Y);
        }
    }
}