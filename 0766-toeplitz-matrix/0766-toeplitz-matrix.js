/**
 * @param {number[][]} matrix
 * @return {boolean}
 */
var isToeplitzMatrix = function (matrix) {
    const n = matrix.length;
    const m = matrix[0].length;
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            if (i > 0 && j > 0 && matrix[i][j] != matrix[i - 1][j - 1]) {
                return false

            }
        }
    }
    return true

};