package java_environment;

import static org.junit.Assert.assertEquals;

import java.util.ArrayList;
import java.util.Collection;

import org.junit.Test;
import org.junit.experimental.runners.Enclosed;
import org.junit.runner.RunWith;
import org.junit.runners.Parameterized;
import org.junit.runners.Parameterized.Parameters;

import rover.Rover;

@RunWith(Enclosed.class)
public class AppTest {
    @RunWith(Parameterized.class)
    public static class RoverRotation {
       
        String facing, expectedFacing;
        String[] commands;

        public RoverRotation(String facing, String[] commands, String expectedFacing) {
            this.facing =facing;
            this.commands = commands;
            this.expectedFacing = expectedFacing;
        }

        @Parameters
        public static Collection<Object[]> setParameters() {
            Collection<Object[]> params = new ArrayList<>();
            // String facing, String[] commands, String expectedFacing
            params.add(new Object[] { "N", new String[] { "l" }, "W" });
            params.add(new Object[] { "N", new String[] { "r" }, "E" });
            params.add(new Object[] { "W", new String[] { "l" }, "S" });
            params.add(new Object[] { "W", new String[] { "r" }, "N" });
            params.add(new Object[] { "W", new String[] { "r", "r" }, "E" } );
    
            return params;
        }

        @Test
        public void rotate() {
            Rover rover = new Rover(facing, 3, 3);

            rover.execute(commands);
            String actual = rover.getFacing();
            assertEquals(expectedFacing, actual);
        }
    }
    
    @RunWith(Parameterized.class)
    public static class RoverMovement {
        int expectedX, expectedY;
        String facing;

        public RoverMovement(String facing, int expectedX, int expectedY) {
            this.facing =facing;
            this.expectedX = expectedX;
            this.expectedY = expectedY;
        }

        @Parameters
        public static Collection<Object[]> setParameters() {
            Collection<Object[]> params = new ArrayList<>();
            // String facing, String[] commands, String expectedFacing
            params.add(new Object[] { "N", 3, 2 });
            params.add(new Object[] { "E", 4, 3});
            params.add(new Object[] { "S", 3, 4});
            params.add(new Object[] { "W", 2, 3});
    
            return params;
        }

        @Test
        public void move() {
            Rover rover = new Rover(facing, 3, 3);

            rover.execute(new String[]{"f"});
            int actualX = rover.getX();
            int actualY = rover.getY();
            assertEquals(expectedX, actualX);
            assertEquals(expectedY, actualY);
        }
    }
}
