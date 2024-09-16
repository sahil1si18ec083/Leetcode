/**
 * @param {string[]} timePoints
 * @return {number}
 */
var findMinDifference = function(timePoints) {

    function getMinutes(timepoint){
        const arr=timepoint.split(":")
        const minutes = Number(arr[0])*60 + Number(arr[1])
        return minutes

    }

    timePoints.sort((a,b)=> getMinutes(a)- getMinutes(b)  )
    const n = timePoints.length;
    console.log(timePoints)
    let min=111111;
    for(let i=0;i<timePoints.length-1;i++){

        let smaller = getMinutes( timePoints[i])
        let bigger = getMinutes( timePoints[i+1])
        min = Math.min(min, bigger-smaller, 1440-bigger+smaller)
        
    }
    let last = getMinutes( timePoints[n-1])
        let first = getMinutes( timePoints[0])
        min = Math.min(min, last-first, 1440-last+first)
    return min

   
    
};
