/**
 * @param {string} s
 * @return {number}
 */
var findTheLongestSubstring = function (s) {
    const map = new Map();
    map.set(0, -1);
    let prefixXor = 0;
    // a ko 1 , b ko 2,  c ko 3
    var maxlength = 0;

    for (let i = 0; i < s.length; i++) {
        if (s[i] == "a" || s[i] == "e" || s[i] == "i" || s[i] == "o" || s[i] == "u") {
            let charCode = s.charCodeAt(i) - 96;
            // a ko 1 assign karo , zero nahi kyu zero ko xor karnay sai pata nahi chalta hai
            prefixXor = prefixXor ^ charCode;


        }
        if (map.has(prefixXor)) {
            // console.log(map.get(prefixXor))
            // console.log({i})
            
            var length = i - map.get(prefixXor)
            maxlength = Math.max(maxlength, length)

        }
        else {
            map.set(prefixXor, i)
        }

    }
    return maxlength

};