/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function (s) {
    var output = ""
    var temp = ""
    s = s.trim()
    for (let i = s.length - 1; i >= 0; i--) {
        if (s.charCodeAt(i) == 32 && s.charCodeAt(i+1) != 32 ) {
            output= output+ temp+" ";
            temp=""

        }
        else if (s.charCodeAt(i)!=32) {
            temp= s[i]+ temp;

        }
    }
    output= output+ temp
    return output;

};