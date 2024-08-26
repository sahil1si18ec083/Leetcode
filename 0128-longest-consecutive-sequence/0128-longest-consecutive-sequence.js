/**
 * @param {number[]} nums
 * @return {number}
 */
var longestConsecutive = function (nums) {

    const n = nums.length;
    const set = new Set();

    for (let i = 0; i < n; i++) {
        set.add(nums[i])
    }

   

    let maxcount = 0;


    for (let i = 0; i < n; i++) {
        let currentvalue = nums[i];

        let count = 0;
        if (set.has(currentvalue-1)){
            continue;
        }
        while (set.has(currentvalue)) {
            count++;
            currentvalue = currentvalue + 1;
        }

        maxcount = Math.max(count, maxcount)

    }
    return maxcount

};