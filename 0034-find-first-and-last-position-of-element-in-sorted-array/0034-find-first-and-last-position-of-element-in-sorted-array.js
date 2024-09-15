/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var searchRange = function (nums, target) {
    function getFirst(nums, target) {
        let low = 0;
        let high = nums.length - 1;
        let unsure = -1;
        while (low <= high) {
            let mid = Math.floor((low + high) / 2);
            if (nums[mid] == target) {
                unsure = mid;
                high = mid - 1;
            }
            else if (nums[mid] < target) {
                low = mid + 1;

            }
            else {
                high = mid - 1;

            }
        }
        return unsure;

    }
    function getlast(nums, target) {
        let low = 0;
        let high = nums.length - 1;
        let unsure = -1;
        while (low <= high) {
            let mid = Math.floor((low + high) / 2);
            if (nums[mid] == target) {
                unsure = mid;
                low = mid + 1;


            }
            else if (nums[mid] < target) {
                low = mid + 1;

            }
            else {
                high = mid - 1;

            }
        }
        return unsure;

    }
    const firstOccurence = getFirst(nums, target)
    const lastOccurence = getlast(nums, target);

    return [firstOccurence,lastOccurence ]


};