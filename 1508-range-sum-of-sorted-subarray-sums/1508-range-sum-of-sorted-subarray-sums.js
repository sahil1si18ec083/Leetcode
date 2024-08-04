/**
 * @param {number[]} nums
 * @param {number} n
 * @param {number} left
 * @param {number} right
 * @return {number}
 */
var rangeSum = function(nums, n, left, right) {
    
   
    const sumarr=[]
    for(let i=0;i<n;i++){
        let sum =0;
        for(let j=i;j<n;j++){
            sum = sum + nums[j];
            sumarr.push(sum)

        }
    }
    sumarr.sort((a,b)=>a-b);
    sum=0;
    console.log({sumarr})
    for(let i=left-1;i<right;i++){
        sum = sum + sumarr[i]
    }
    return sum %(Math.pow(10,9)+7)
};