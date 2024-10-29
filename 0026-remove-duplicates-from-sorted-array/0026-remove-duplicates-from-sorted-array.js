/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
    let i=0;
    let j=1;
    const n = nums.length;
    while(j<n){
        if(nums[i]==nums[j]){
            j++;
        }
        else{
            nums[i+1]=nums[j];
            i++;
            j++;
        }
    }
    return i+1;
    
};