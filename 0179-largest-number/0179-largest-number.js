/**
 * @param {number[]} nums
 * @return {string}
 */
var largestNumber = function (nums) {


    nums.sort((a, b) => {
        let astring = String(a);
        let bstring = String(b);

        let poss1 = Number(astring + bstring); // 102
        let poss2 = Number(bstring + astring); // 210

        if(poss2> poss1){
            return 1;
        }
        else{
            return -1;
        }



    });
    let res="";
    for(let i=0;i<nums.length;i++){
        res += String(nums[i]);
    }
    while(res.length>1 && res[0]=='0'){
        res = res.slice(1);
    }
    return res;

};