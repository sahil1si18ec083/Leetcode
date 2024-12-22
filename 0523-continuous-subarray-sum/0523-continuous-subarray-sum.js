/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */
var checkSubarraySum = function (nums, k) {


    const n = nums.length;
    if (n < 2) return false;
    const map = new Map();

    map.set(0, -1);
    let prefixsum = 0;

    for (let i = 0; i < n; i++) {
        prefixsum = prefixsum + nums[i];
        let rem = prefixsum % k;
        if (map.has(rem) && (i - map.get(rem) > 1)) {
            return true;
        }
        if (!map.has(rem)) {
            map.set(rem, i);
        }

    }
    return false;
};