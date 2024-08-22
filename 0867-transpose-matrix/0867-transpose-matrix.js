/**
 * @param {number[][]} matrix
 * @return {number[][]}
 */
var transpose = function (matrix) {

    const n = matrix.length;
    const m = matrix[0].length;
    const temp = []
    for (let it = 0; it < m; it++) {
        temp.push([])
    }
    console.log({temp})
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            temp[i].push(matrix[j][i])
        }
    }
    
    return temp

};