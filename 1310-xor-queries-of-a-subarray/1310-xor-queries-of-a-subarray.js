/**
 * @param {number[]} arr
 * @param {number[][]} queries
 * @return {number[]}
 */
var xorQueries = function (arr, queries) {
    // BRUTE FORCE
    // TIME COMPLEXITY O(N*Q)
    const res = []
    // Suppose we have elements from a1, a2,a3,a4
    // Xor of a3^a4 will be eqaul to xor of (xor upto a3 and xor upto a4)
    let xor = 0;
    function xorfn(i,j,prefixxor){
        // console.log(prefixxor,index1,index2)
        return (i==-1?0:prefixxor[i-1]) ^ prefixxor[j]
    }

    const prefixxor = []
    for (let i = 0; i < arr.length; i++) {
        xor = xor ^ arr[i]
        prefixxor.push(xor)

    }
    for(let i=0;i<queries .length;i++){
        res.push(xorfn(queries[i][0], queries[i][1],prefixxor ))
    }

    return res
};