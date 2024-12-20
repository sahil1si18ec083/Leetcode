/**
 * @param {number[]} numbers
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    
  
    let i = 0;
    let n = nums.length;
    let j = n - 1;
    console.log(nums)

    while (j > i) {
        if (nums[i] + nums[j] == target) {
            return [i+1, j+1];
        }
        else if (nums[i] + nums[j] < target) {
            i++;
        }
        else {
            j--;
        }
    }
    return false;
    
};