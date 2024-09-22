/**
 * @param {number[]} bills
 * @return {boolean}
 */
var lemonadeChange = function (bills) {
    let count_5 = 0;
    let count_10 = 0;
    let count_20 = 0;
    for (let i = 0; i < bills.length; i++) {
        if (bills[i] == 5) {
            count_5++;
        }
        else if (bills[i] == 10) {
            if (count_5 < 1) {
                return false;
            }
            count_5 = count_5 - 1;
            count_10 = count_10 + 1;

        }
        else {
            if (count_5==0){
                return false
            }
            if (count_10 < 1 && count_5 < 1) {
                return false;
            }
            if (count_10 == 0 && count_5 < 3) {
                return false

            }
            if (count_10 == 0) {
                count_5 = count_5 - 3;
            }
            else {
                count_5 = count_5 - 1;
                count_10 = count_10 - 1;
                count_20= count_20 + 1;
            }
        }

    }

    return true

};