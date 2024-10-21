/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function (s) {
    const myset = new Set();

    let i = 0;
    let j = 0;
    const n = s.length;
    let max=0;
    while (j < n) {
        while (myset.has(s[j])) {
            myset.delete(s[i])
            i++;
        }
        myset.add(s[j]);
        j++;
        console.log(i,j)
        if(j-i>max){
            max= j-i
        }
        
    }
    return max

};