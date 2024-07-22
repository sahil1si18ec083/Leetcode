/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */
var containsNearbyDuplicate = function (nums, k) {
    const n = nums.length;
    let i = 0;
    let j = 0;
    const set = new Set()
    while (j < n) {
        set.add(nums[j]);
        j++
        while (j - i > k) {
            set.delete(nums[i])
            i++
        }
        if (j - i <= k && set.has(nums[j]) && j != i) {
            return true;
        }
        
    }
    return false
};