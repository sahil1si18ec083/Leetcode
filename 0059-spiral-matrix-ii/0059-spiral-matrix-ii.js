/**
 * @param {number} n
 * @return {number[][]}
 */
var generateMatrix = function (n) {


    const matrix = []
    for (let i = 0; i < n; i++) {
        matrix.push(Array(n).fill(-1))
    }

    var count = 0;
    var left = 0;
    var right = n - 1;
    var top = 0;
    var bottom = n - 1;
    while (count < n * n) {
        for (let i = left; i <= right && count < n * n; i++) {
            matrix[top][i] = count + 1;
            count++;
        }
        top++;
        for (let i = top; i <= bottom && count < n * n; i++) {
            matrix[i][right] = count + 1;

            count++;
        }
        right--
        for (let i = right; i >= left && count < n * n; i--) {
            matrix[bottom][i] = count+1;
            count++;
        }
        bottom--
        for (let i = bottom; i >= top && count < n * n; i--) {
            matrix[i][left] = count+1;
            count++;
        }
        left++;

    }

    return matrix

};