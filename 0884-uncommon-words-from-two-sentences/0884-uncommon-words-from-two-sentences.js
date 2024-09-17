/**
 * @param {string} s1
 * @param {string} s2
 * @return {string[]}
 */
var uncommonFromSentences = function(s1, s2) {
    const s1arr=s1.split(" ")
    const s2arr= s2.split(" ")
    const maps1= new Map()
    const maps2= new Map()
    for(let i=0;i<s1arr.length;i++){
        if (maps1.has(s1arr[i])){
            maps1.set(s1arr[i], maps1.get(s1arr[i])+1)
        }
        else{
             maps1.set(s1arr[i],1)
        }
    }
    for(let i=0;i<s2arr.length;i++){
        if (maps2.has(s2arr[i])){
            maps2.set(s2arr[i], maps2.get(s2arr[i])+1)
        }
        else{
             maps2.set(s2arr[i],1)
        }
    }
    const res=[]
    // console.log({maps2})
    // console.log({maps1})

    for(let i=0;i<s1arr.length;i++){
        if (maps1.get(s1arr[i])==1 && !maps2.has(s1arr[i])){
            res.push(s1arr[i])
        }
    }
     for(let i=0;i<s2arr.length;i++){
        if (maps2.get(s2arr[i])==1 && !maps1.has(s2arr[i])){
            res.push(s2arr[i])
        }
    }
    return res
    
};