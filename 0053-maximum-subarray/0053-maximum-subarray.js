/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function (nums) {
    // using kadane's algorithm
    const n = nums.length;
    let currentsum = 0;
    let maxsum = -100000;
    for (let i = 0; i < n; i++) {
        currentsum = currentsum + nums[i];
        maxsum= Math.max(currentsum, maxsum);
        if (currentsum<0){
           currentsum= 0; 
        }
    }
    return maxsum

};