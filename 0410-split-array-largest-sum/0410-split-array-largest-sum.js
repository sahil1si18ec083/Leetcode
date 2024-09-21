/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var splitArray = function(nums, k) {
    function ispossible(mid, nums, k){
        let sum=0;
        let c=1;
        for(let i=0;i<nums.length;i++){
            if (nums[i]>mid){
                return false
            }
            if(sum+nums[i]<=mid){
                sum = sum + nums[i];

            }
            else{
                c++;
                sum = nums[i];
                if(c>k){
                    return false
                }
            }

        }
        return true
    }


    let low = Math.max(...nums);
    let high = nums.reduce((acc,current)=>acc+current,0);
    let res=-1;
    while(low<=high){
        let mid = Math.floor((low+high)/2);
        if (ispossible(mid, nums, k)){
            res = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return res;
};