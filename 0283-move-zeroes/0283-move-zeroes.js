/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var moveZeroes = function(nums) {
    function swap(nums,i,j){
        let temp = nums[i];
        nums[i]= nums[j];
        nums[j]= temp
    }
    let mid=0;
    let low=0; // low aise pointer hai jiskay left mai sirf non zeros hongay

    while(mid<nums.length){
        if (nums[mid]!=0){
            swap(nums,mid,low);
            low++
        }
        mid++;
    }

    return nums
};