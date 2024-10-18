/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var subsetsWithDup = function(nums) {
    const solve=(nums,index,res,subarray)=>{
        if(index===nums.length){
            const x=[...subarray]
   
            
     res.push(x) 
       
            return ;
        }
           let x=nums[index];
        subarray.push(x);
         solve(nums,index+1,res,subarray);
        subarray.pop() 
        // excludes
         while(index+1<=nums.length-1 && nums[index]==nums[index+1]){
            index++;
        }
         solve(nums,index+1,res,subarray);
        // includes condition
     
    }

    let index=0;
    const res=[];
    const subarray=[];
    nums.sort((a,b)=>a-b)

     solve(nums,index,res,subarray)
     return res
    
};