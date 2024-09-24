/**
 * @param {number[]} arr1
 * @param {number[]} arr2
 * @return {number}
 */
var longestCommonPrefix = function (arr1, arr2) {

    const set = new Set()
    let max = 0;

    for (let i = 0; i < arr2.length; i++) {
        const val = arr2[i];
        const valString = val.toString()
        for (let j = 0; j < valString.length; j++) {
            if (!set.has(valString.slice(0, j + 1))) {
                set.add(valString.slice(0, j + 1))
            }
        }
    }

    for (let i = 0; i < arr1.length; i++) {
        let val = arr1[i].toString()
        for (let j = 0; j < val.length; j++) {

            if (set.has(val.slice(0, j + 1))) {
                max = Math.max(max, j + 1)
            }

        }
    }
    return max

};