/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function (strs) {
    let j = 0;
    while (j < strs[0].length) {
        var isflag = true;
        let character = strs[0][j];
        // console.log(character)
        for (let i = 0; i < strs.length; i++) {
            if (strs[i].length <= j) {
                isflag = false;
            }

            if (character != strs[i][j]) {

                isflag = false;
            }
        }

        if (isflag == true) {
            j++;
        }
        else {

            break;
        }
    }
    if (j == 0) {
        return ""
    }
    return strs[0].slice(0, j)
};