/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var subarraysDivByK = function (nums, k) {
    const n = nums.length;
    let prefsum = 0;
    let count = 0;
    const map = new Map();
    map.set(0, 1)
    for (let i = 0; i < n; i++) {
        prefsum = prefsum + nums[i];
        let res = prefsum % k;
        if (res < 0) {
            res = res + k;
        }

        if (map.has(res)) {
            count = count + map.get(res);
            map.set(res, map.get(res) + 1)
        }
        else {
            map.set(res, 1)
        }
    }
    return count

};
