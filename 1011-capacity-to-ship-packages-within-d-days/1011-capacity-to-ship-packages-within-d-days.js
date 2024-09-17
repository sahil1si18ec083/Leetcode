/**
 * @param {number[]} weights
 * @param {number} days
 * @return {number}
 */
const getMaxAndSum = (arr) => {
    let max = arr[0];
    let sum = 0;
    for (let i = 0; i < arr.length; i++) {
        if (arr[i] > max) {
            max = arr[i]
        }
        sum = sum + arr[i]
    }
    return [max, sum];

}
function calculateDays(weights, cap) {
  let days = 1; // First day.
    let load = 0;
    let n = weights.length; // size of array.
    for (let i = 0; i < n; i++) {
        if (load + weights[i] > cap) {
            days += 1; // move to next day.
            load = weights[i]; // load the weight.
        } else {
            // load the weight on the same day.
            load += weights[i];
        }
    }
    return days;




}
var shipWithinDays = function (weights, days) {
    var maximum = Math.max(...weights)

    

    let unsure;
    let low = maximum;
    let high =weights.reduce((acc,current)=> acc+current,0);
    while (low <= high) {
        let midCapacity = Math.floor((low + high) / 2);
        let daysCalculated = calculateDays(weights, midCapacity);
        if (daysCalculated <= days) {
            unsure = midCapacity;
            high = midCapacity - 1;

        }
        else {
            low = midCapacity + 1;
        }

    }
    return unsure;


};