/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var numSubarrayProductLessThanK = function(nums, k) {
    let product=1;
    const n = nums.length;
    let i=0;
    let j=0;
    if (k==0 || k==1){
        return 0;
    }
    let count=0;

    while(j<n){
        product= product*nums[j];
        while (product>=k){
            product = product / nums[i];
            i++;
        }
        count = count + (j-i+1)
        j++;
    }
    return count;
};