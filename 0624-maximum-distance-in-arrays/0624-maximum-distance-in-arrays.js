/**
 * @param {number[][]} arrays
 * @return {number}
 */
var maxDistance = function (arrays) {
    let minimum = 10000;
    let maximum = -100000;
    let index = 0;
    let minimum2 = 10000;
    let maximum2 = -100000;
    let index2 = 0;

    for (let i = 0; i < arrays.length; i++) {
        for (let j = 0; j < arrays[i].length; j++) {

            if (arrays[i][j] < minimum) {
                minimum = arrays[i][j];
                index = i;
            }
        }
    }
    for (let i = 0; i < arrays.length; i++) {
        for (let j = 0; j < arrays[i].length; j++) {

            if (arrays[i][j] > maximum && i != index) {
                maximum = arrays[i][j];

            }
        }
    }
     for (let i = 0; i < arrays.length; i++) {
        for (let j = 0; j < arrays[i].length; j++) {

            if (arrays[i][j] > maximum2) {
                maximum2 = arrays[i][j];
                index = i;
            }
        }
    }
    for (let i = 0; i < arrays.length; i++) {
        for (let j = 0; j < arrays[i].length; j++) {

            if (arrays[i][j] < minimum2 && i != index) {
                minimum2 = arrays[i][j];

            }
        }
    }
    return Math.max(Math.abs(maximum - minimum), Math.abs(maximum2 - minimum2))

};