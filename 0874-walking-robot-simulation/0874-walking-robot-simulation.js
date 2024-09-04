/**
 * @param {number[]} commands
 * @param {number[][]} obstacles
 * @return {number}
 */
function getNewDirection(direction, commandvalue) {

    if (commandvalue == -2) {
        if (direction == 0) {
            return 3;
        }
        else if (direction == 1) {
            return 0
        }
        else if (direction == 2) {
            return 1;

        }
        else if (direction == 3) {
            return 2;

        }

    }
    else if (commandvalue == -1) {
        if (direction == 0) {
            return 1

        }
        else if (direction == 1) {
            return 2;

        }
        else if (direction == 2) {
            return 3;

        }
        else if (direction == 3) {
            return 0;

        }

    }

}
var robotSim = function (commands, obstacles) {
    let direction = 0; // by default is north
    let x = 0;
    let y = 0;
    let max = 0;

    const map = new Map()
    // store obstacles in map
    for (let i = 0; i < obstacles.length; i++) {
        map.set(JSON.stringify(obstacles[i]), 0)
    }
    console.log(map)

    for (let i = 0; i < commands.length; i++) {




        if (commands[i] == -1 || commands[i] == -2) {
            direction = getNewDirection(direction, commands[i])
        }
        

        else {
            console.log({direction})
            if (direction == 0) {
                for (let j = 0; j < commands[i]; j++) {
                   if (map.has(JSON.stringify([x, y+1]))) {
                        break;
                    }
                    else {
                        y = y + 1;

                    }

                }

            }
            else if (direction == 1) {
                for (let j = 0; j < commands[i]; j++) {
                    console.log([x,y])
                    if (map.has(JSON.stringify([x+1, y]))) {
                        console.log("hello")
                        break;
                    }
                    else {
                      x++;

                    }

                }

            }
            else if (direction == 2) {
               for (let j = 0; j < commands[i]; j++) {
                   if (map.has(JSON.stringify([x, y-1]))) {
                        break;
                    }
                    else {
                        y = y - 1;

                    }

                }

            }
            else if (direction == 3) {
                for (let j = 0; j < commands[i]; j++) {
                    if (map.has(JSON.stringify([x-1, y]))) {
                        break;
                    }
                    else {
                        x = x - 1;

                    }

                }

            }
        }
        console.log(x,y)
        if (x * x + y * y > max) {
            max = x * x + y * y;
        }
    }

    return max
};