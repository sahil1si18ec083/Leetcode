/**
 * @param {number[]} nums
 * @return {number}
 */
var longestSubarray = function (nums) {
    // This problem is same as Longest Subarray With Maximum value
    let max = nums[0];
    let maxlength = 1;
    let count = 0;
    for (let i = 0; i < nums.length; i++) {

        if (nums[i] == max) {
            count++;
            maxlength = Math.max(count,maxlength);
        }
        else if (nums[i]>max){
            max= nums[i];
            count=1;
            maxlength=1;

        }
        else{
            count=0;

        }


    }

    return maxlength
};