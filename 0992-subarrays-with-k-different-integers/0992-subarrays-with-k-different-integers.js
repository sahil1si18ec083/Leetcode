/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
   function fun(nums,target){
        if(target<0){
            return 0
        }
        let i=0;
        let j=0;
        const n = nums.length;
        const map = new Map();
        let res=0;
        while(j<n){
            if (map.has(nums[j])){
                map.set(nums[j], map.get(nums[j])+1)
            }
            else{
                map.set(nums[j], 1)
            }
            while(map.size>target){
                if (map.get(nums[i])==1){
                    map.delete(nums[i])
                }
                else{
                     map.set(nums[i], map.get(nums[i])-1)
                }
                i++
            }
            res = res + (j-i+1);
            j++;

        }
        return res
    }
var subarraysWithKDistinct = function(nums, k) {
  

    return fun(nums,k)- fun(nums,k-1)
    
};