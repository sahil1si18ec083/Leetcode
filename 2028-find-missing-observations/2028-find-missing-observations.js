/**
 * @param {number[]} rolls
 * @param {number} mean
 * @param {number} n
 * @return {number[]}
 */
var missingRolls = function (rolls, mean, n) {
    const m = rolls.length;
    const total = m + n;
    const temp = Array(n).fill(-1);
    let sum_of_all_dices = mean * total;
    let sum_of_m_dices = rolls.reduce((acc, current) => acc + current, 0);
    let sum_of_n_dices = sum_of_all_dices - sum_of_m_dices;
    let val = Math.floor(sum_of_n_dices / n);
    let extra = sum_of_n_dices % n;
    console.log({sum_of_n_dices})
    if (sum_of_n_dices<0 || val>6 || sum_of_n_dices<n){
        return []
    }
    if (val==6 && extra>0){
        return []
    }

    for (let i = 0; i < n; i++) {
        temp[i]= val +(extra>0?1:0)


        extra--;
    }
    return temp

};