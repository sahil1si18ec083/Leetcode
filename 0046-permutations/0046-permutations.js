/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var permute = function (nums) {
    function swap(i,j,nums){
        let temp = nums[i];
        nums[i]= nums[j];
        nums[j]= temp;
    }
    function solve(res, nums, idx) {
        if (idx >= nums.length) {
            const numscopy = [...nums]
            res.push(numscopy)
        }
        for (let i = idx; i <= nums.length - 1; i++) {
            swap(i, idx, nums);
            solve(res, nums, idx + 1);
            swap(i, idx, nums);


        }
    }


    const res = []

    let idx = 0;
    

    solve(res, nums, idx)

    return res

};