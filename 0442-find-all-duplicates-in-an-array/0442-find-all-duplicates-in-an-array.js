/**
 * @param {number[]} nums
 * @return {number[]}
 */
var findDuplicates = function(nums) {
    const map = new Map();
    const res=[]
    for (let i=0;i<nums.length;i++){
        if(!map.has(nums[i])){
            map.set(nums[i],1)
        }
        else{
            
                res.push(nums[i])
            
             map.set(nums[i],map.get(nums[i])+1)
        }
    }
    return res;

};