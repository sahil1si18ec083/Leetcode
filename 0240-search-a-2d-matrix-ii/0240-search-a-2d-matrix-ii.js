/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var searchMatrix = function (matrix, target) {
    const n = matrix.length;
    const m = matrix[0].length;
    let high = 0;
    let low = m - 1;
    while (low >= 0 && high <= n - 1) {
        if (matrix[high][low] == target) {
            return true
        }
        else if (matrix[high][low] < target) {
            high++;
        }
        else {
            low--;
        }

    }
    return false

};