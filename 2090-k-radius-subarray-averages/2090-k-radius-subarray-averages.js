/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
var getAverages = function (nums, k) {
    const res = []
    const n = nums.length;
    console.log(n)
    if (n <= 2*k) {
        return new Array(n).fill(-1)
    }
    for (let i = 0; i < k; i++) {
        res.push(-1)
    }

    let sum = 0;
    for (let it = 0; it <= 2 * k; it++) {
        sum = sum + nums[it]
    }
    res.push(Math.floor(sum / (2 * k + 1)))
    let i = 0;
    let j = 2 * k;

    while (j < n - 1) {
        j++;
        sum = sum + nums[j];
        sum = sum - nums[i];
        i++;
        res.push(Math.floor(sum / (2 * k + 1)))
    }
    for (let i = 0; i < k; i++) {
        res.push(-1)
    }
    return res


};