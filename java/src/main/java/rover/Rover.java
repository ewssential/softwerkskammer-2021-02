package rover;

import java.util.stream.Stream;

public class Rover {

    public Rover(Direction direction, int x, int y) {
        facing = direction;
        position = new Position(x,y);
    }

    private Direction facing;

    public Direction getFacing() {
        return facing;
    }


    private Position position;

    public int getX() {
        return position.getX();
    }

    public int getY() {
        return position.getY();
    }

    public Rover execute(String[] commands) {
        Stream.of(commands).map(Command::Parse).forEach(command -> {
            this.facing = command.ChangeDirection(this.facing);
            position = position.ChangePosition(command, this.facing);
        });
        return this;
    }

    public class Position {
        private final int x;
        private final int y;

        public Position(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public int getX() {
            return x;
        }

        public int getY() {
            return y;
        }

        public Position ChangePosition(Command command, Direction direction) {
            switch (direction) {
                case North:
                    return new Position(x, y - command.StepWidth());
                case South:
                    return new Position(x, y + command.StepWidth());
                case East:
                    return new Position(x + command.StepWidth(), y);
                case West:
                    return new Position(x - command.StepWidth(), y);
                default:
                    throw new IllegalArgumentException(":-(");
            }
        }
    }

    public enum Command {
        Forward() {
            @Override
            public Direction ChangeDirection(Direction direction) {
                return direction;
            }

            @Override
            public int StepWidth() {
                return 1;
            }
        },
        Backward() {
            @Override
            public Direction ChangeDirection(Direction direction) {
                return direction;
            }

            @Override
            public int StepWidth() {
                return -1;
            }
        },
        Left() {
            @Override
            public Direction ChangeDirection(Direction direction) {
                return direction.Previous();
            }

            @Override
            public int StepWidth() {
                return 0;
            }
        },
        Right() {
            @Override
            public Direction ChangeDirection(Direction direction) {
                return direction.Next();
            }

            @Override
            public int StepWidth() {
                return 0;
            }
        };

        public static Command Parse(String command) {
            switch (command) {
                case "l":
                    return Left;
                case "r":
                    return Right;
                case "f":
                    return Forward;
                case "b":
                    return Backward;
                default:
                    throw new IllegalArgumentException("wrong facing -.-'");
            }
        }

        public abstract Direction ChangeDirection(Direction direction);

        public abstract int StepWidth();
    }

    public enum Direction {
        North() {
            @Override
            public Direction Next() {
                return East;
            }

            @Override
            public Direction Previous() {
                return West;
            }
        },
        East {
            @Override
            public Direction Next() {
                return South;
            }

            @Override
            public Direction Previous() {
                return North;
            }
        },
        South {
            @Override
            public Direction Next() {
                return West;
            }

            @Override
            public Direction Previous() {
                return East;
            }
        },
        West {
            @Override
            public Direction Next() {
                return North;
            }

            @Override
            public Direction Previous() {
                return South;
            }
        };

        public abstract Direction Next();

        public abstract Direction Previous();
    }
}
