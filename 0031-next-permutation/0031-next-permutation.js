/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
function swap(nums, low, high) {
    let temp = nums[low];
    nums[low] = nums[high];
    nums[high] = temp;
}
function reverse(nums, low, high) {
    while (low <= high) {
        swap(nums, low, high);
        low++;
        high--;
    }
}
var nextPermutation = function (nums) {
    let golaindex = -1;

    const n = nums.length;
    for (let i = n - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) {
            golaindex = i;
            break;
        }
    }
    if (golaindex == -1) {
        return reverse(nums, 0, n - 1);
    }

    let swappedindex = -1;

    for (let i = n - 1; i >= 0; i--) {
        if (nums[i] > nums[golaindex]) {
            swappedindex = i;
            break;

        }
    }
    swap(nums, golaindex, swappedindex);

    reverse(nums, golaindex + 1, n - 1);

    return nums;

};