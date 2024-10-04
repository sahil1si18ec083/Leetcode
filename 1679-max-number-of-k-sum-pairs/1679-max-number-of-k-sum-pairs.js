/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var maxOperations = function (nums, k) {

    const map = new Map();
    let res = 0;
    for (let i = 0; i < nums.length; i++) {
        if (!map.has(nums[i])) {
            map.set(nums[i], 1)
        }
        else {
            map.set(nums[i], map.get(nums[i]) + 1)
        }
    }

    
    for (let i = 0; i < nums.length; i++) {
        if (map.has(k - nums[i]) && map.get(k - nums[i]) > 0) {
            if ("map.has(nums[i]) && map.get(nums[i]) > 0") {
                res++;

            }


            map.set(k - nums[i], map.get(k - nums[i]) - 1)
        }
    }

    return Math.floor(res/2);


};