/**
 * @param {number[]} nums
 * @param {number} p
 * @return {number}
 */
var minSubarray = function (nums, p) {
    let prefixsum = 0;
    let n = nums.length;
    const mp = new Map();
    mp.set(0, -1);

    let min = n;
    let totalsum = 0;
    for (let i = 0; i < n; i++) {
        totalsum = totalsum + nums[i];
    }
    let r = (totalsum) % p; 
    if(r==0){
        return 0;
    }


    for (let i = 0; i < n; i++) {
        prefixsum = prefixsum + nums[i];

        let r1 = (prefixsum%p + p)%p;
        let rminusr1= (r1-r+p)%p;

        if(mp.has(rminusr1)){
            let diff = i- mp.get(rminusr1);
             min = Math.min(min, diff);

        }
       
            mp.set(r1, i)
    }

   return min == n? -1 : min;
};