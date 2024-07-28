/**
 * @param {number[][]} mat
 * @return {number[][]}
 */
var diagonalSort = function (mat) {
    const n = mat.length;
    const m = mat[0].length;
    const map = new Map();
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            if (map.has(j - i)) {
                const arr = map.get(j - i);
                arr.push(mat[i][j]);
                map.set(j - i, arr)

            }
            else {
                map.set(j - i, [mat[i][j]])
            }
        }
    }
    map.forEach((value, key) => {
        const arr = value.sort((a, b) => a - b);
        map.set(key, arr)
    })
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            const arr = map.get(j - i);
            mat[i][j] = arr[0];
            arr.shift();
            map.set(j - i, arr)

        }
    }
    return mat

};