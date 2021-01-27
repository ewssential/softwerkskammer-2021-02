## Setup
nodejs (runs with 10.16.3)

VS Code
### VS CodePlugins
we used:
- [Live Share](https://marketplace.visualstudio.com/items?itemName=MS-vsliveshare.vsliveshare)
- [Test Explorer UI](https://marketplace.visualstudio.com/items?itemName=hbenl.vscode-test-explorer)
- [Test Explorer Live Share](https://marketplace.visualstudio.com/items?itemName=hbenl.vscode-test-explorer-liveshare)
- [Jest Test Eplorer](https://marketplace.visualstudio.com/items?itemName=kavod-io.vscode-jest-test-adapter)

### Docker FUN FUN FUN
Docker is needed

Docker Commands with no node installation:
  1. Build Image Command: docker build -t swk-rover-js .
  2. Run Tests Command: docker run --rm -v $(pwd):/usr/src/app swk-rover-js:latest node_modules/.bin/jest
  3. Debug Tests Command: docker run --rm -p 9229:9229 -v $(pwd):/usr/src/app swk-rover-js:latest node --inspect-brk=0.0.0.0:9229 node_modules/.bin/jest --runInBand

npm commands for Docker -- see package.json

## Your Task
You’re part of the team that explores Mars by sending remotely controlled vehicles to the surface of the planet. Develop an API that translates the commands sent from earth to instructions that are understood by the rover.

## Requirements
- ~~You are given the initial starting point (x,y) of a rover and the direction (N,S,E,W) it is facing.~~
- ~~The rover receives a character array of commands.~~
- ~~Implement commands that move the rover forward/backward (f,b).~~
- ~~Implement commands that turn the rover left/right (l,r).~~
- Implement wrapping at edges. But be careful, planets are spheres. Connect the x edge to the other x edge, so (1,1) for x-1 to (5,1), but connect vertical edges towards themselves in inverted coordinates, so (1,1) for y-1 connects to (5,1).
- Implement obstacle detection before each move to a new square. If a given sequence of commands encounters an obstacle, the rover moves up to the last possible point, aborts the sequence and reports the obstacle.
## Rules
- Hardcore TDD. No Excuses!
- Change roles (driver, navigator) after each TDD cycle.
- No red phases while refactoring.
- Be careful about edge cases and exceptions. We can not afford to lose a mars rover, just because the developers overlooked a null pointer.
