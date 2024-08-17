/**
 * @param {string[]} words
 * @param {string} pattern
 * @return {string[]}
 */
var findAndReplacePattern = function(words, pattern) {
    function checkpattern(word,pattern){
        let flag = true;
        if (word.length!=pattern.length){
            return false;
        }
        const map = new Map();
        for(let i=0;i<word.length;i++){
            if(map.has(word[i])){
                if(map.get(word[i])!=pattern[i]){
                    return false
                }
            }
            else{
                map.set(word[i], pattern[i])
            }
        }
        map.forEach((value,key)=>{
            map.delete(key)
        })
        for(let i=0;i<pattern.length;i++){
            if(map.has(pattern[i])){
                if(map.get(pattern[i])!=word[i]){
                    return false
                }
            }
            else{
                map.set(pattern[i], word[i])
            }
        }

    return true
    }
    const result = []

    for(let i=0;i<words.length;i++){
        if (checkpattern(words[i], pattern)){
            result.push(words[i])
        }
    }
    return result
};