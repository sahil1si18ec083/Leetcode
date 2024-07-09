/**
 * @param {number[][]} customers
 * @return {number}
 */
var averageWaitingTime = function (customers) {
    const n = customers.length
    let t = customers[0][0];
    let totaltime = 0;
    for (let i = 0; i < n; i++) {
        if (customers[i][0]>t){
           
            t= customers[i][0]
        }

        let finaltime = t+ customers[i][1];
        t= t+ customers[i][1];
        let diff = finaltime- customers[i][0];
        totaltime= totaltime+ diff;
       
    }

    return totaltime / n
};