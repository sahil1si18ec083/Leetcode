/**
 * @param {number[]} nums
 * @return {number}
 */
var longestConsecutive = function(nums) {
    const map =  new Map();

    for(let i=0;i<nums.length;i++){
        map.set(nums[i], 1);
    }

    let maxdiff =0;

    for(let i=0;i<nums.length;i++){
        if(map.has(nums[i]+1)){
            continue;
        }
        let num = nums[i];
        let diff =0;
       

        while(map.has(num)){
            diff= diff+1;
            num = num-1;
        }
        maxdiff = Math.max(maxdiff, diff);
    }
    return maxdiff;
    
};