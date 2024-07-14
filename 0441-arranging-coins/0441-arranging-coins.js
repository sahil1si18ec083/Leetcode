/**
 * @param {number} n
 * @return {number}
 */
var arrangeCoins = function(n) {
    let low=1;
    let high = n;
    let ans=1;
    while(low<=high){
        let mid = Math.floor((low+high)/2);
        if (mid*(mid+1)/2  <=n){
            low= mid+1;
            ans = mid;
        }
        else{
            high = mid-1;
        }
    }
    return ans
};