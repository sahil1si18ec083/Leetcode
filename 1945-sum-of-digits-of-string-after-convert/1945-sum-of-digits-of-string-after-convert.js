/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
var getLucky = function(s, k) {

    let sum=""
    for(let i=0;i<s.length;i++){
        sum = sum + String(s.charCodeAt(i)-96);

    }
    let sumNumber =0;
    for(let i=0;i<sum.length;i++){
        sumNumber= sumNumber+ Number(sum[i])
    }

    for(let i=0;i<k-1;i++){
        let n = sumNumber;
        let s=0;
        while(n!=0){
            s= s + n%10;
            n= Math.floor(n/10);

        }
        sumNumber= s;
    }
    return sumNumber
    
};