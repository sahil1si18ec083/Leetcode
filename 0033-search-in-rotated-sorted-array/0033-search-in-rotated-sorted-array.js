/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var search = function (nums, target) {
    let low = 0;
    const n = nums.length;
    let high = n - 1;
    while (low <= high) {
        let mid = Math.floor((low + high) / 2);
        if (nums[mid] == target) return mid;
        else if (nums[mid] >= nums[low]) {
            // if left part is sorted
            if (target >= nums[low] && target <= nums[mid]) {
                high = mid - 1;

            }
            else {
                low = mid + 1;
            }
        }
        else {
            if (target >= nums[mid] && target <= nums[high]) {

                low = mid + 1;

            }
            else {
                high = mid - 1;

            }
        }
    }
    return -1;


};