/**
 * @param {number[]} nums
 * @return {number[]}
 */
var rearrangeArray = function (nums) {
    let pos = 0;
    let neg = 1;
    const numscopy=new Array(nums.length).fill(0)
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] > 0) {
            numscopy[pos] = nums[i];
            pos = pos + 2;

        }
        else {
            numscopy[neg] = nums[i];
            neg = neg + 2;
        }
    }
    return numscopy

};