/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNonDuplicate = function (nums) {
    let low = 0;
    const n = nums.length;
    let high = n - 1;
    // check if the first elment is single
    if (n == 1) {
        return nums[0]
    }
    if (nums[0] != nums[1]) {
        return nums[0]
    }
    if (nums[n - 1] != nums[n - 2]) {
        return nums[n - 1]
    }

    while (low <= high) {
        let mid = Math.floor((low + high) / 2);
        if ((mid == 0 || nums[mid] != nums[mid - 1]) && (mid == n - 1 || nums[mid] != nums[mid + 1])) {
            return nums[mid]
        }
        else if ((mid%2==0 && nums[mid]==nums[mid+1])){
            low= mid+1;
        }
        else if ((mid%2==1 && nums[mid]!=nums[mid+1])){
            low= mid+1
        }
         else if ((mid%2==0 && nums[mid]==nums[mid-1])){
            high = mid-1
        }
        else if ((mid%2==1 && nums[mid]!=nums[mid-1])){
            high = mid-1
        }
    }

};