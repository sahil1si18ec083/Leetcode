/**
 * @param {number[]} time
 * @param {number} totalTrips
 * @return {number}
 */
var minimumTime = function(time, totalTrips) {
    let low=1;
    let high =Math.max(...time)* totalTrips;
    let unsure;
    console.log({high})
    while(low<=high){
        let mid= Math.floor((low+high)/2);
        let totaltime = 0;
        for(let i=0;i<time.length;i++){
            totaltime= totaltime+ Math.floor(mid/time[i])
        }
        if (totaltime>=totalTrips){
            console.log({mid})
            unsure= mid;
            high = mid-1


        }
        else {
            low= mid+1

        }

    }

    return unsure
    
};