/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var backspaceCompare = function(s, t) {
    let scopy="";
    let tcopy="";
    for(let i=0;i<s.length;i++){
        if(s[i]!="#"){
            scopy = scopy + s[i]
        }
        else{
            scopy = scopy.slice(0, scopy.length-1)
        }
    }
        for(let i=0;i<t.length;i++){
        if(t[i]!="#"){
            tcopy = tcopy + t[i]
        }
        else{
            tcopy = tcopy.slice(0, tcopy.length-1)
        }
    }
    return scopy==tcopy
    
};