/**
 * @param {number[]} nums
 * @return {number[]}
 */
function helper(number, index) {
    let mask = 1 << index;
    let res = number & mask;
    if (res == 0) return true;
    return false;
}
var singleNumber = function (nums) {
    let n = nums.length;
    let totalxor = 0;
    for (let i = 0; i < n; i++) {
        totalxor = totalxor ^ nums[i];
    }
    let left = 0;
    let right = 0;
    let index = 0;

    while (totalxor != 0) {
        let andvalue = totalxor & 1;
        if (andvalue != 0) {
            break;

        }
        else {
            index++;
            totalxor = totalxor >> 1;
        }
    }
    for (let i = 0; i < n; i++) {
        if (helper(nums[i], index)) {
            left = left ^ nums[i];
        }
        else {
            right = right ^ nums[i];
        }
    }

    return [left, right];
};