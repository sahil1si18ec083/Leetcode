/**
 * @param {string} s
 * @param {string} goal
 * @return {boolean}
 */
var rotateString = function(s, goal) {
    s= s+s;
   
    if (s.includes(goal)){
        return true
    }

    return false

   
    
};