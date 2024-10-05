/**
 * @param {string} s1
 * @param {string} s2
 * @return {boolean}
 */
var checkInclusion = function (s1, s2) {
    // This is a problem of fixed window
    function checkZeroMap(map) {
        let flag = true;
        map.forEach((key, value) => {
           
            if (key != 0) {
                flag = false;
            }
        })
        return flag;
    }
    const map = new Map();
    for (let i = 0; i < s1.length; i++) {
        if (map.has(s1[i])) {
            map.set(s1[i], map.get(s1[i]) + 1)
        }
        else {
            map.set(s1[i], 1)
        }
    }
    // fixed window mai kya hota hai
    for (let i = 0; i < s1.length; i++) {
        if (map.has(s2[i])) {
            map.set(s2[i], map.get(s2[i]) - 1)
        }
    }
    console.log(map)
    if (checkZeroMap(map)==true) {
        return true;
    }
    let i = 0;
    let j = s1.length-1;
    console.log(j,s2.length - 1)
    while (j < s2.length - 1) {
       
        
        if (map.has(s2[i])) {
            map.set(s2[i], map.get(s2[i]) + 1)
        }
        i++;
        j++;
        if (map.has(s2[j])) {
            map.set(s2[j], map.get(s2[j]) - 1)
        }
        if (checkZeroMap(map)) {
            return true;
        }



    }
    return false


};