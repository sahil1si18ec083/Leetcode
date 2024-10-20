/**
 * @param {string} s
 * @param {string} p
 * @return {number[]}
 */
function checkAllZeros(map) {
    let isnonzero = false;
    map.forEach((value, key) => {
        
        if (value != 0) {
            isnonzero = true;
        }
    })
    return !isnonzero
}
var findAnagrams = function (s, p) {
    const map = new Map();
    for (let i = 0; i < p.length; i++) {
        if (map.has(p[i])) {
            map.set(p[i], map.get(p[i]) + 1)
        }
        else {
            map.set(p[i], 1)

        }
    }
    // lets cover first window
    for (let i = 0; i < p.length; i++) {
        if (map.has(s[i])) {
            map.set(s[i], map.get(s[i]) - 1)
        }


    }
    
    const res=[];
    if (checkAllZeros(map)){
        res.push(0);
    }
    
    let i=0;
    let j=p.length-1;
    while(i<s.length-p.length+1){
        j++;
        
        if (map.has(s[i])){
            map.set(s[i],map.get(s[i])+1)
        }
         if (map.has(s[j])){
            map.set(s[j],map.get(s[j])-1)
        }
     
        
        i++;
           if (checkAllZeros(map)){
            res.push(i)
        }
       
        

    }
    return res

};