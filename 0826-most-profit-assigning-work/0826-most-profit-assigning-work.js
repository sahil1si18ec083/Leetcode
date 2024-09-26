/**
 * @param {number[]} difficulty
 * @param {number[]} profit
 * @param {number[]} worker
 * @return {number}
 */
var maxProfitAssignment = function (difficulty, profit, worker) {

    const myMap = new Map()
    for (let i = 0; i < difficulty.length; i++) {
        if (myMap.has(profit[i])) {
            myMap.set(profit[i], Math.min(difficulty[i], myMap.get(profit[i])))

        }
        else {

            myMap.set(profit[i], difficulty[i])
        }
    }
    console.log(myMap)

    let totalProfit = 0;

    // Sort the arrays
    worker.sort((a, b) => a - b);
    profit.sort((a, b) => a - b);
    let i = worker.length - 1;
    let j = profit.length - 1;


    while (i >= 0 && j >= 0) {
        if (worker[i] < myMap.get(profit[j])) {
            j--;
        }
        else {
            console.log(difficulty[j])
            totalProfit = totalProfit + profit[j]
            i--;
        }
    }

    return totalProfit;


};