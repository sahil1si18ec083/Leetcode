/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isIsomorphic = function(s, t) {
     if (s.length!=t.length){
            return false;
        }
        const map = new Map();
        for(let i=0;i<s.length;i++){
            if(map.has(s[i])){
                if(map.get(s[i])!=t[i]){
                    return false
                }
            }
            else{
                map.set(s[i], t[i])
            }
        }
        map.forEach((value,key)=>{
            map.delete(key)
        })

        for(let i=0;i<t.length;i++){
            if(map.has(t[i])){
                if(map.get(t[i])!=s[i]){
                    return false
                }
            }
            else{
                map.set(t[i], s[i])
            }
        }
 

    return true
};