/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function (nums) {
    let low = 0;
    let high = 0;
    const n = nums.length;

    while (high < n) {
        if (nums[high] != nums[low]) {
            low++;
            nums[low] = nums[high];


        }
        high++;
    }
    return low + 1;


};