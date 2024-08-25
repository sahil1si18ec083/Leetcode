/**
 * @param {string} s
 * @return {boolean}
 */
var repeatedSubstringPattern = function (s) {
    function check(s,t){
       
        const n = s.length;
        const m = t.length;
        if (n%m!=0){
            return false; 
        }
        let temp=""
        for(let i=0;i<n/m;i++){
            temp= temp + t;
        }
        if (temp==s){
            return true
        }
        return false
    }

    const n = s.length;
    if (n==1) return false
    for(let i=0;i<n/2;i++){
        if (check(s, s.slice(0,i+1))){
            return true;
        }
    }
    return false;
};