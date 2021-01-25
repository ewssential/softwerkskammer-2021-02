const each = require("jest-each").default;

const {Rover, f, b, l, r, N, E, S, W} = require('./rover');

describe("mars rover rotation", () => {
  each([
    [N, [l], W],
    [N, [r], E],
    [W, [l], S],
    [W, [r], N],
    [W, [r, r], E],
  ]).it(
    `''%s' turn '%s' then expected facing: '%s'`,
    (facing, command, expectedFacing) => {
      const ro = Rover(facing);
      ro.execute(command);
      expect(ro.facing).toBe(expectedFacing);
    }
  );

  it("access rover facing as return value", () => {
    const rover = Rover(W);
    let { facing } = rover.execute([r]);
    expect(facing).toBe(N);
    facing = rover.execute([r]).facing;
    expect(facing).toBe(E);
  });

  it("access rover facing as getter value", () => {
    const rover = Rover(W);
    rover.execute([r]);
    expect(rover.facing).toBe(N);
    rover.execute([r]);
    expect(rover.facing).toBe(E);
  });
});

describe("mars rover movement", () => {
  // the world looks like this:
  // (0,0)  ...  (5,0)
  // ...    ...  ...
  // (5,0)  ...  (5,5)

  const forwardCommand = f;
  each([
    [N, 3, 2],
    [E, 4, 3],
    [S, 3, 4],
    [W, 2, 3],
  ]).it(
    `'${forwardCommand}', '%s' then y: '%d' x: '%d'`,
    (direction, expectedX, expectedY) => {
      const rover = Rover(direction, 3, 3);
      rover.execute([forwardCommand]);
      expect(rover.x).toBe(expectedX);
      expect(rover.y).toBe(expectedY);
    }
  );

  const backwardCommand = b;
  each([
    [N, 3, 4],
    [E, 2, 3],
    [S, 3, 2],
    [W, 4, 3],
  ]).it(
    `'${backwardCommand}', '%s' then y: '%d' x: '%d'`,
    (direction, expectedX, expectedY) => {
      const rover = Rover(direction, 3, 3);
      rover.execute([backwardCommand]);
      expect(rover.x).toBe(expectedX);
      expect(rover.y).toBe(expectedY);
    }
  );
});
