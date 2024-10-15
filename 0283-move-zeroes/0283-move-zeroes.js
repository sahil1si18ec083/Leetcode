/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var moveZeroes = function(nums) {
    let low=0;
    let mid=0;
    const n = nums.length;
    while(mid<n){
        if(nums[mid]!=0){
            
            [nums[mid], nums[low]]= [nums[low], nums[mid]];
            low++;
            mid++;
        }
        else{
            mid++;
        }
    }
    return nums;
    
};