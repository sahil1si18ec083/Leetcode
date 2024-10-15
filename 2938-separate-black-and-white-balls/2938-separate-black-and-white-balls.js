/**
 * @param {string} s
 * @return {number}
 */
var minimumSteps = function(s) {
    let count=0;
    let onessofar=0;
    for(let i=0;i<s.length;i++){
        if(s[i]=="0"){
            count= count+ onessofar;
        }
        else{
            onessofar++;
        }
    }
    return count;
    
};