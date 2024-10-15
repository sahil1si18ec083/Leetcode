/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function (nums) {
    let i = 0;
    let j = 0;
    const n = nums.length;

    while (j < n) {
        if (nums[i] == nums[j]) {
            j++;

        }
        else {
            i++;
            nums[i] = nums[j];

        }
    }
    i++;
    nums[i]= nums[j-1]

    return i


};