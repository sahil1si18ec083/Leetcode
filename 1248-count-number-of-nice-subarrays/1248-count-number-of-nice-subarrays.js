/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var numberOfSubarrays = function(nums, k) {
    function helper(nums, k){
        if (k<0){
            return 0;
        }
        let oddcount=0;
        let res=0;
        const n =nums.length;
        let i=0;
        let j=0;
        while(j<n){
            if (nums[j]%2==1){
                oddcount++;
            }
            while(oddcount>k){
                if (nums[i]%2==1){
                    oddcount--;
                }
                i++;
            }
            res = res + (j-i+1);
            j++;
        }
        return res;


    }


    return helper(nums, k)- helper(nums, k-1)
    
};