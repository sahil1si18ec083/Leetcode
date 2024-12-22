/**
 * @param {number[]} nums
 * @return {number}
 */
var findMaxLength = function(nums) {

    let res =0;
    const map = new Map();
    let prefixsum =0;
    const n = nums.length;

    map.set(0, -1);
    let maxlength=0;

    for(let i=0;i<n;i++){
        if(nums[i]==0){
           prefixsum = prefixsum -1;
        }
        else{
            prefixsum = prefixsum + 1;
        }

        if(map.has(prefixsum)){
            let diff = i- map.get(prefixsum);
            maxlength= Math.max(diff, maxlength);

        }
        else{
            map.set(prefixsum, i);
        }

    }

    return maxlength;
    
};