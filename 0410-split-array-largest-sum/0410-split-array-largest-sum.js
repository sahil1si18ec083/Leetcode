/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var splitArray = function (nums, k) {
    function isPossible(nums, k, mid) {
        const n = nums.length;
        let subarraycount = 1;
        let sum = 0;
        for (let i = 0; i < n; i++) {
            if (nums[i] > mid) {
                return false
            }
            if (sum + nums[i] <= mid) {
                sum = sum + nums[i]
            }
            else {
                subarraycount++;
                if (subarraycount > k) {
                    return false
                }
                sum = nums[i]
            }
        }

        return true
    }


    var low = Math.min(...nums)
    var high = nums.reduce((acc, current) => acc + current, 0);
    var ans;
    while (low <= high) {
        let mid = Math.floor((low + high) / 2);
        console.log({ mid })
        if (isPossible(nums, k, mid)) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return ans;

};