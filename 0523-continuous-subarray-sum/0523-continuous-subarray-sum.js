/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */
var checkSubarraySum = function (nums, k) {
    let prefixsum = 0;
    const map = new Map();
    map.set(0, -1);

    for (let i = 0; i < nums.length; i++) {
        prefixsum = prefixsum + nums[i];
        let res = prefixsum % k;

        if (map.has(res) && i - map.get(res) > 1) {
            return true;
        }
        if (!map.has(res)) {
            map.set(res, i)

        }



    }
    return false

};