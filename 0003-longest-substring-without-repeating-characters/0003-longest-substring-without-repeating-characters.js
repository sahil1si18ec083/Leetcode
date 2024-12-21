/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    const n = s.length;
    let i=0;
    let j=0;
    const mp = new Map();
    let maxlength=0;

    while(j<n){

        while(mp.has(s[j])){
            mp.set(s[i], mp.get(s[i])-1);
            if(mp.get(s[i])==0){
                mp.delete(s[i]);
            }
            i++;
        }

        mp.set(s[j],1);
        maxlength= Math.max(maxlength, j-i+1);
        j++;


    }
    return maxlength;
    
};