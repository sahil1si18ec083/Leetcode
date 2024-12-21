/**
 * @param {string[]} words
 * @param {string} order
 * @return {boolean}
 */
function  compare(a, b, map){
    let i = 0;
    let j = 0;
    let m = a.length;
    let n = b.length;
    while (i < m && j < n) {
        if (map.get(a[i]) < map.get(b[j])) {
            return true;
        }
        else if (map.get(a[i])==map.get(b[j])){
            i++;
            j++;
        }
        else {
            return false;
        }

    }
    if (i < m) {
        return false;
    }
    return true;


}
var isAlienSorted = function (words, order) {

    const map = new Map();
    let n = words.length;

    for (let i = 0; i < order.length; i++) {
        map.set(order[i], i);

    }
    for (let i = 1; i < n; i++) {
        let bool = compare(words[i - 1], words[i], map);
        if (bool == false) {
            return false;
        }

    }
    return true;
};