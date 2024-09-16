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
    console.log(timePoints)
    let min=111111;
    for(let i=0;i<timePoints.length-1;i++){

        let bigger = Math.max(getMinutes( timePoints[i]),getMinutes( timePoints[i+1]) );
        let smaller = Math.min(getMinutes( timePoints[i]),getMinutes( timePoints[i+1]) );
        min = Math.min(min, bigger-smaller, 1440-bigger+smaller)
        
    }
    let bigger = Math.max(getMinutes( timePoints[timePoints.length-1]),getMinutes( timePoints[0]) );
        let smaller = Math.min(getMinutes( timePoints[timePoints.length-1]),getMinutes( timePoints[0]) );
        min = Math.min(min, bigger-smaller, 1440-bigger+smaller)
    return min

   
    
};
