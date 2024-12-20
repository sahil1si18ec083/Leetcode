/**
 * @param {number[]} nums
 * @return {number[]}
 */
var productExceptSelf = function(nums) {
    const n = nums.length;

    const res = new Array(n).fill(0);
    let prod=1;
    for(let i= n-1;i>=0;i--){
        res[i]= prod;
        prod= prod *  nums[i];
    }
    prod=1;
    for(let i=0;i<n;i++){
        res[i]= res[i] * prod;
        prod = prod * nums[i];
    }
    return res;
    
};