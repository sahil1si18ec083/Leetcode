/**
 * @param {number[][]} intervals
 * @return {number[][]}
 */
var merge = function(intervals) {
    intervals.sort((a,b)=>{
        return a[0]- b[0];
    })

    const res =[];

    res.push(intervals[0]);

    const n = intervals.length;
    for(let i=1;i<n;i++){
        let oldvaluefirst = res[res.length-1][0];
        let oldvaluesecond = res[res.length-1][1];

        if(intervals[i][0]>oldvaluesecond){
            res.push(intervals[i]);
        }
        else{
            res.pop();
            res.push([oldvaluefirst, Math.max(oldvaluesecond, intervals[i][1])]);
        }

    }
    return res;
    
};