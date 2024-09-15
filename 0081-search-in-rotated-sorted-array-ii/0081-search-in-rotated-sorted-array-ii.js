

/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var search = function (nums, target) {
    const n = nums.length;
    let low = 0;
    let high = n - 1;
    while (low <= high) {
        let mid = Math.floor((low + high) / 2);
        if (nums[mid] == target) {
            return true;
        }
        else if (nums[low]==nums[mid] && nums[mid]==nums[high] && nums[mid]!=target){
            low++;
            high--;
        }
        // if left part is sorted
        else if (nums[mid] >= nums[low]) {
            // if target lies then skip the right part
            if (target >= nums[low] && target <= nums[mid]) {
                high = mid - 1;
            }
            else {
                low = mid + 1
            }

        }
        else {
            // if right part is sorted
            if (target >= nums[mid] && target <= nums[high]) {
                // if it exits on right side then skip the lft portion

                low = mid + 1
            }
            else {
                high = mid - 1;

            }
        }
    }

    return false
};