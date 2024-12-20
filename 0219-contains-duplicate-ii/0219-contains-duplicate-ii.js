/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */
var containsNearbyDuplicate = function (nums, k) {

    const map = new Map();
    let n = nums.length;
    let i = 0;
    let j = 0;
    while (j < n) {
       
        while (j - i > k) {
            map.set(nums[i], map.get(nums[i]) - 1);
            
            if (map.get(nums[i]) == 0) {
                map.delete(nums[i]);
            }
            i++;
        }
         if (map.has(nums[j])) {
          
            return true;
        }

        map.set(nums[j], 1);
        j++;
    }
    return false;
};