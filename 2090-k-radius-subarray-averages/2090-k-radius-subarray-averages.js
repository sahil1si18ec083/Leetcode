/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
var getAverages = function(nums, k) {
    // first calculate the sum of  the first window
    var sum=0;
    const n = nums.length;
    const res=[]
    if (k>=n || n<=2*k){
        for(let i=0;i<n;i++){
            res.push(-1)
        }
        return res;
    }
    for (let i=0;i<k;i++){
        res.push(-1);
    }
    for (let i=0;i<=2*k;i++){
        sum = sum + nums[i]
    }
    console.log({sum})
    let i=0;
    let j=2*k;
    
     res.push(Math.floor(sum/(2*k+1)));
    while(j<n-1){

        sum = sum-nums[i];
        j++;
        sum = sum + nums[j];
        i++;
        res.push(Math.floor(sum/(2*k+1)));

    }
      for (let i=0;i<k;i++){
        res.push(-1);
    }
    return res;
    console.log(res)
};