package rover;

import java.util.Arrays;

public class Rover {
    private String[] directionArray = { "N", "E", "S", "W" };

    public Rover(String Facing, int X, int Y) {
        facing = Facing;
        x = X;
        y = Y;
    }

    private String facing;

    public String getFacing() {
        return facing;
    }

    private int x;
    public int getX() {
        return x;
    }
    private int y;
    public int getY() {
        return y;
    }

    public Rover execute(String[] commands) {
        for (String command : commands) {
            switch (command) {
                case "l":
                    facing = directionArray[getPreviousDirectionIndex(facing)];
                    break;
                case "r":
                    facing = directionArray[getNextDirectionIndex(facing)];
                    break;
                    case "f":
                    case "b":
                      move(command);
                      break;
                default:
                    break;
            }
        }
        return this;
    }

    private void move(String command) {
        int incrementer = command == "b" ? -1 : 1;
        switch (facing) {
          case "N":
            y -= incrementer;
            break;
          case "S":
            y += incrementer;
            break;
          case "E":
            x += incrementer;
            break;
          case "W":
            x -= incrementer;
            break;
          default:
            throw new Error("wrong facing -.-'");
        }
    }

    private int indexOf(String c) {
        return Arrays.asList(directionArray).indexOf(c);
    }

    private int getIndexOfMinusOne(String direction) {
        int returner = indexOf(direction) - 1;
        return returner;
    }

    private int getIndexOfPlusOne(String direction) {
        int returner = indexOf(direction) + 1;
        return returner;
    }

    private int normalizeDirectionIndex(int index) {
        int returner = (index + directionArray.length) % directionArray.length;
        return returner;
    }

    private int getPreviousDirectionIndex(String direction) {
        int returner = normalizeDirectionIndex(getIndexOfMinusOne(direction));
        return returner;
    }

    private int getNextDirectionIndex(String direction) {
        int returner = normalizeDirectionIndex(getIndexOfPlusOne(direction));
        return returner;
    }
}

// private class RoverReturnValues {
//     String facing;
//     int x;
//     int y;
// }