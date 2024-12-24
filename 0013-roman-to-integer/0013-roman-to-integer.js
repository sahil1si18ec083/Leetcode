/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function (s) {
    const map = new Map();
    map.set("I", 1);
    map.set("V", 5);
    map.set("X", 10);
    map.set("L", 50);
    map.set("C", 100);
    map.set("D", 500);
    map.set("M", 1000);

    let i = 0;
    const n = s.length;
    let res = 0;

    while (i < n) {
        if ((i < n - 1) && (s[i] == "I" && s[i + 1] == "V") || (s[i] == "I" && s[i + 1] == "X") || (s[i] == "X" && s[i + 1] == "L") || (s[i] == "X" && s[i + 1] == "C") || (s[i] == "C" && s[i + 1] == "D") || (s[i] == "C" && s[i + 1] == "M")) {
            res = res + map.get(s[i + 1]) - map.get(s[i]);
            i = i + 2;
        }
        else {
            res = res + map.get(s[i]);
            i++;
        }
        console.log({ res })
    }

    return res;


};