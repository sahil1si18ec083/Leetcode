/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function(nums) {

    let votes =0;
    let candidate = nums[0];
    let n = nums.length;
    for(let i=0;i<n;i++){
        if(votes==0){
            candidate= nums[i];
        }
        if(nums[i]==candidate){
            votes++;
        }
        else{
            votes--;
        }
        
    }
    return candidate;
    
};