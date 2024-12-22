/**
 * @param {number[]} nums
 * @param {number} k
 * @return {void} Do not return anything, modify nums in-place instead.
 */
function reverse(low, high, nums){
    while(high>=low){

        let temp = nums[low];
        nums[low]= nums[high];
        nums[high]= temp;
        low++;
        high--;
    }
} 
var rotate = function (nums, k) {

    const n = nums.length;
    k = k % n;
    if(k==0) return nums;

    reverse(0, n - k - 1, nums);

    reverse(n - k, n - 1, nums);

    reverse(0, n - 1, nums);

    return nums;



};