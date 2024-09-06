/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var spiralOrder = function (matrix) {
    const n = matrix.length;
    const m = matrix[0].length;
    const res = []

    var count = 0;
    var left = 0;
    var right = m - 1;
    var top = 0;
    var bottom = n - 1;
    while (count < m * n) {
        for (let i = left; i <= right && count < m * n; i++) {
            res.push(matrix[top][i]);
            count++;
        }
        top++;
        for (let i = top; i <= bottom && count < m * n; i++) {
            res.push(matrix[i][right]);
            count++;
        }
        right--
        for (let i = right; i >= left && count < m * n; i--) {
            res.push(matrix[bottom][i]);
            count++;
        }
        bottom--
        for (let i = bottom; i >= top && count < m * n; i--) {
            res.push(matrix[i][left]);
            count++;
        }
        left++;

    }

    return res

};