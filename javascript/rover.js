
// VARIABLE DECLARATION
const DIRECTION = {
    N: "N",
    E: "E",
    S: "S",
    W: "W"
  }
  
  const MOVEMENTS = {
    f: "f",
    b: "b",
    l: "l",
    r: "r"
  }
  
  const f = MOVEMENTS.f;
  const b = MOVEMENTS.b;
  const l = MOVEMENTS.l;
  const r = MOVEMENTS.r;
  
  const N = DIRECTION.N;
  const E = DIRECTION.E;
  const S = DIRECTION.S;
  const W = DIRECTION.W;
  
  const directionArray = [N, E, S, W];
  
  const getIndexOfMinusOne = (direction) => directionArray.indexOf(direction) - 1;
  const getIndexOfPlusOne = (direction) => directionArray.indexOf(direction) + 1;
  const normalizeDirectionIndex = (index) =>
    (index + directionArray.length) % directionArray.length;
  const getPreviousDirectionIndex = (direction) =>
    normalizeDirectionIndex(getIndexOfMinusOne(direction));
  const getNextDirectionIndex = (direction) =>
    normalizeDirectionIndex(getIndexOfPlusOne(direction));
  
  const Rover = (facing, x, y) => {
    const move = (command) => {
      const incrementer = command == b ? -1 : 1;
      switch (facing) {
        case N:
          y -= incrementer;
          break;
        case S:
          y += incrementer;
          break;
        case E:
          x += incrementer;
          break;
        case W:
          x -= incrementer;
          break;
        default:
          throw new Error("wrong facing -.-'");
      }
    };
  
    return {
      execute(commands) {
        commands.forEach((command) => {
          switch (command) {
            case l:
              facing = directionArray[getPreviousDirectionIndex(facing)];
              break;
            case r:
              facing = directionArray[getNextDirectionIndex(facing)];
              break;
            case f:
            case b:
              move(command);
              break;
            default:
              throw new Error("wrong command -.-'");
          }
        });
        return { facing: facing, x, y };
      },
  
      get x() {
        return x;
      },
      get y() {
        return y;
      },
      get facing() {
        return facing;
      },
    };
  };
 
module.exports = {Rover, f, b, l, r, N, E, S, W};
