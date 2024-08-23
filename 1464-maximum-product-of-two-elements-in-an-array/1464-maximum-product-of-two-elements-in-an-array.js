/**
 * @param {number[]} nums
 * @return {number}
 */
var maxProduct = function (nums) {
    let largest = 0;
    let secondlargest = 0;
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] > largest && largest == 0) {
            largest = nums[i]
        }
        else if (nums[i] <= largest && nums[i] >= secondlargest) {
            secondlargest = nums[i]
        }
        else if (nums[i] > largest) {
            secondlargest = largest;
            largest = nums[i];
            
        }
    }
  
    return ((largest - 1) * (secondlargest - 1))

};