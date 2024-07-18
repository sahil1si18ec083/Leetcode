/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
function getval(nums, k) {
    let oddcount = 0;
    let res = 0;
    let i = 0;
    let j = 0;
    const n = nums.length;
    while (j < n) {
        if (nums[j] % 2 == 1) {
            oddcount++;
        }
        while (oddcount > k) {

            if (nums[i] % 2 == 1) {
                oddcount--
            }
            i++;
        }
        res=res+j-i+1
        j++;
    }
    return res
}
var numberOfSubarrays = function (nums, k) {

    return getval(nums,k)- getval(nums,k-1)

};