package rover;

import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.Arguments;
import org.junit.jupiter.params.provider.MethodSource;

import java.util.stream.Stream;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static rover.Rover.Direction.*;

public class RoverTest {
    private static Stream<Arguments> provideArgumentsForRotationTest() {
        return Stream.of(
                Arguments.of(North, new String[]{"l"}, West),
                Arguments.of(North, new String[]{"r"}, East),
                Arguments.of(West, new String[]{"l"}, South),
                Arguments.of(West, new String[]{"r"}, North),
                Arguments.of(West, new String[]{"r", "r"}, East)
        );
    }

    private static Stream<Arguments> provideArgumentsForMovementTest() {
        return Stream.of(
                Arguments.of(North, 3, 2),
                Arguments.of(East, 4, 3),
                Arguments.of(South, 3, 4),
                Arguments.of(West, 2, 3)
        );
    }

    @ParameterizedTest
    @MethodSource("provideArgumentsForRotationTest")
    public void rotate(Rover.Direction facing, String[] commands, Rover.Direction expectedFacing) {
        Rover rover = new Rover(facing, 3, 3);

        rover.execute(commands);
        Rover.Direction actual = rover.getFacing();
        assertEquals(expectedFacing, actual);
    }

    // The rovers view
    //           N
    //   (0,0)  ...  (5,0)
    // W ...    ...  ...    E
    //   (5,0)  ...  (5,5)
    //          S

    @ParameterizedTest
    @MethodSource("provideArgumentsForMovementTest")
    public void move(Rover.Direction facing, int expectedX, int expectedY) {
         Rover rover = new Rover(facing, 3, 3);

         rover.execute(new String[]{"f"});
         int actualX = rover.getX();
         int actualY = rover.getY();
         assertEquals(expectedX, actualX);
         assertEquals(expectedY, actualY);
     }
}

