const directionArray = ["N", "E", "S", "W"];

const getPreviousDirectionIndex = (direction) =>
  (directionArray.indexOf(direction) + directionArray.length - 1) %
  directionArray.length;

const getNextDirectionIndex = (direction) =>
  (directionArray.indexOf(direction) + directionArray.length + 1) %
  directionArray.length;

const rover = (facing, x, y) => ({
  execute(commands) {
    commands.forEach((command) => {
      switch (command) {
        case "l":
          facing = directionArray[getPreviousDirectionIndex(facing)];
          break;
        case "r":
          facing = directionArray[getNextDirectionIndex(facing)];
          break;
        case "f":
            y--;
            break;
        default:
          throw new Error("false direction -.-'");
      }
    });
    return {facing: facing, x, y};
  },
  get x() {return x;},
  get y() {return y;}
});

describe("mars rover rotation", () => {
  it('rover directs N, get command "l", direct W', () => {
    expect(rover("N").execute(["l"]).facing).toBe("W");
  });

  it('rover directs N, get command "r", direct E', () => {
    expect(rover("N").execute(["r"]).facing).toBe("E");
  });

  it('rover directs W, get command "l", direct S', () => {
    const {facing} = rover("W").execute(["l"]);
    expect(facing).toBe("S");
  });

  it('rover directs W, get command "r", direct N', () => {
    const {facing} = rover("W").execute(["r"]);
    expect(facing).toBe("N");
  });

  it('rover directs W, get command "r", direct N', () => {
    const {facing} = rover("W").execute(["r", "r"]);
    expect(facing).toBe("E");
  });

  it('rover directs W, get command "r", direct N', () => {
    const r = rover("W");
    let {facing} = r.execute(["r"]);
    expect(facing).toBe("N");
    facing = r.execute(["r"]).facing;
    expect(facing).toBe("E");
  });
});

describe("mars rover movement", () => {
  it("rover is on point (3,3) directs 'N' and command 'f' executed, new point is (3,2)", () => {
      const r = rover("N",3,3);
      r.execute(["f"]);
      expect(r.x).toBe(3);
      expect(r.y).toBe(2);
    });
});
