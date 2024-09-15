/**
 * @param {number[]} time
 * @param {number} totalTrips
 * @return {number}
 */
var minimumTime = function(time, totalTrips) {
    let low=1;
    let high = Math.max(...time)* totalTrips;
    let res;
    while(low<=high){
        let mid= Math.floor((low+high)/2);
        let total=0;
        for(let i=0;i<time.length;i++){
            total= total+ Math.floor(mid/time[i]);
        }
        if(total>=totalTrips){
            res= mid;
            high = mid-1;
        }
        else{
            low= mid+1;
        }
    }
    return res
    
};