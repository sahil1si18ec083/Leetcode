/**
 * @param {number[]} nums
 * @return {number}
 */
var longestSubarray = function (nums) {
    let max = nums[0]
    for (let i = 1; i < nums.length; i++) {
        max = Math.max(max, nums[i])
    }
    let maxlength = 1;
    let count = 0;
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] == max) {
            count++;
        }
        else {
            count = 0;
        }
        maxlength = Math.max(count, maxlength);
    }

    return maxlength
};