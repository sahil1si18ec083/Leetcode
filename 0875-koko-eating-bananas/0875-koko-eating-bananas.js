/**
 * @param {number[]} piles
 * @param {number} h
 * @return {number}
 */
var minEatingSpeed = function(piles, h) {
    let low=1;
    let high = Math.max(...piles);
    let ans;
    while(low<=high){
        let mid= Math.floor((low+high)/2);
        let hours=0;
        for(let i=0;i<piles.length;i++){
            hours += Math.ceil(piles[i]/mid)
        }
        if (hours<=h){
            ans= mid;
            high=mid-1
        }
        else{
            low = mid+1;
        }
    }
    return ans
    
};