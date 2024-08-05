/**
 * @param {number[]} nums
 * @return {number[]}
 */
var sortedSquares = function (nums) {
    const n = nums.length;
    const res = new Array(n).fill(-1);
    let low = 0;
    let high = n - 1;
    let j=n-1;
    while (low <= high) {
        if (nums[low] * nums[low] <= nums[high] * nums[high]) {
            res[j] = nums[high] * nums[high];
            high--;

        }
        else {
            res[j] = nums[low] * nums[low];
            low++;
        }
        j--;
    }
    return res

};