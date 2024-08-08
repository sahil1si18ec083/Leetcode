/**
 * @param {number[]} changed
 * @return {number[]}
 */
var findOriginalArray = function (changed) {
    const n = changed.length;
     const res = [];
    if (n%2==1){
        return res
    }
    const map = new Map();
    for (let i = 0; i < changed.length; i++) {
        if (map.has(changed[i])) {
            map.set(changed[i], map.get(changed[i]) + 1)
        }
        else {
            map.set(changed[i], 1)
        }
    }
   

    for (let i = 0; i < changed.length; i++) {
        if (map.has(changed[i]) && map.has(changed[i] * 2)) {
            res.push(changed[i])
            map.set(changed[i], map.get(changed[i]) - 1)
            map.set(changed[i] * 2, map.get(changed[i] * 2) - 1);
            if (map.get(changed[i]) == 0) {
                map.delete(changed[i])
            }
            if (map.get(changed[i] * 2) == 0) {
                map.delete(changed[i] * 2)
            }
        }

    }
    if (map.size!=0){
        return []
    }
    if (res.length==n/2){
        return res
    }
    return []




};