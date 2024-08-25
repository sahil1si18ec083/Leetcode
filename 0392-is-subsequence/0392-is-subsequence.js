/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isSubsequence = function(s, t) {
    const n = s.length;
    var j=0;
    for(let i=0;i<t.length;i++){
        if (t[i]==s[j]){
            j++
        }
    }
    if (j>=n){
        return true
    }
    return false
};