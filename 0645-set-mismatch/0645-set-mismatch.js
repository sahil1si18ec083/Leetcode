/**
 * @param {number[]} nums
 * @return {number[]}
 */
var findErrorNums = function (nums) {
    const n = nums.length;
    let actualsum = nums.reduce((acc, current) => {
        return acc + current
    }, 0);

    let expectedsum = (n * (n + 1)) / 2;
    let setsum = 0;
    const set = new Set();
    for (let i = 0; i < n; i++) {
        set.add(nums[i])
    }
    set.forEach((value) => {
        setsum = setsum + value;
    })
    let repeatednumber = actualsum - setsum;
    let missingnumber = repeatednumber + expectedsum - actualsum;

    return [repeatednumber, missingnumber]

};