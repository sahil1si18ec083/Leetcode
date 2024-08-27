/**
 * @param {string} s
 * @return {number}
 */
var maxDepth = function(s) {
    var max=0;
    var count=0;

    for(let i=0;i<s.length;i++){
        if (s[i]=="("){
            count++;
        }
        else if (s[i]==")"){
            count--
        }
        max= Math.max(max,count)

    }
    return max
    
};