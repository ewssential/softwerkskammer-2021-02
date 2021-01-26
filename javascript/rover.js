
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

const Rover = (facing, x, y) => {

  const turnLeftFacing = () => {
    switch (facing) {
      case N:
        facing = W;
        break;
      case E:
        facing = N;
        break;
      case S:
        facing = E;
        break;
      case W:
        facing = S;
        break;
    }
  }
  const turnRightFacing = () => {
    switch (facing) {
      case N:
        facing = E;
        break;
      case E:
        facing = S;
        break;
      case S:
        facing = W;
        break;
      case W:
        facing = N;
        break;
    }
  }

  const turn = (command) => (command === l ? turnLeftFacing : turnRightFacing)();

  const move = (command) => {
    const incrementer = command === b ? -1 : 1;
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
          case r:
            turn(command);
            break;
          case f:
          case b:
            move(command);
            break;
          default:
            throw new Error("wrong command -.-'");
        }
      });
      return { facing, x, y };
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
