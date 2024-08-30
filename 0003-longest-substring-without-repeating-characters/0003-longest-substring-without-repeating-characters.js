/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function (s) {
    let maxlength = 0;
    let j = 0;
    let i = 0;
    const myset = new Set();
    const n = s.length;
    while (j < n) {

        if (myset.has(s[j])) {
            myset.delete(s[i])
            i++;

        }
        else {
            myset.add(s[j])
            j++;
        }
        if (j - i > maxlength) {
            maxlength = j - i;
        }

    }
    return maxlength

};