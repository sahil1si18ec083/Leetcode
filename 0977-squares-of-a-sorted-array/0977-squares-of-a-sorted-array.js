/**
 * @param {number[]} nums
 * @return {number[]}
 */
var sortedSquares = function (nums) {

    let n = nums.length;
    const res = new Array(n).fill(0);

    let low = 0;
    let high = n - 1;

    while (low <= high) {
        if (nums[low] * nums[low] > nums[high] * nums[high]) {
            res[n - 1] = nums[low] * nums[low];
            low++;
        }
        else {
            res[n - 1] = nums[high] * nums[high];
            high--;
        }
        n--;
    }

    return res;



};