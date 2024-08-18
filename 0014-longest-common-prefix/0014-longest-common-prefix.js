/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function (strs) {
    var pointer = 0;  // This  is for keeping track of the length of substring
    var iterator = 0; // this is for iterating on flower
    while (iterator < strs[0].length) {
        for (let i = 0; i < strs.length; i++) {
            debugger;
            var isSame = true;
             debugger;
             console.log(strs[i][pointer], strs[i][0])
            if (strs[i][pointer] != strs[0][pointer]) {
                console.log(strs[i][pointer], strs[0][i])
                isSame = false;
                break;

            }


        }
        if (isSame) {
            debugger;
            pointer++
        }
        iterator++

    }

    return strs[0].substring(0, pointer) // iterate over the strs[0] and return the value fl

};