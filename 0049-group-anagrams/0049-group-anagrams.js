/**
 * @param {string[]} strs
 * @return {string[][]}
 */
var groupAnagrams = function (strs) {
    const map = new Map();
    const res=[];
    for (let i = 0; i < strs.length; i++) {
        let rotatedstr = strs[i].split("").sort().join("");
        
        if (!map.has(rotatedstr)) {
            map.set(rotatedstr, [strs[i]])
        }
        else {
            let arr = map.get(rotatedstr)
            arr.push(strs[i])
            map.set(rotatedstr, arr)
        }
    }
    console.log(map)
    map.forEach((value,key)=>{
       
        res.push(value)
    })
    return res
};