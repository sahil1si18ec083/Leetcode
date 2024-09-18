/**
 * @param {number[]} nums
 * @return {string}
 */
var largestNumber = function(nums) {
    nums.sort((a,b)=>{
       
        let astring = String(a);
        let bstring = String(b);
        let ab = Number(astring + bstring);
        let ba = Number(bstring+ astring);
        if (ab>ba){
            return -1
        }
        return 1

        
    })

    var res=""
    console.log(nums)


    for(let i=0;i<nums.length;i++){
        res = res + String(nums[i])
    }
    while(res.length>1  && res[0]=="0"){
        res = res.slice(1)
    }

    return res
    
};