/**
 * @param {number[]} bloomDay
 * @param {number} m
 * @param {number} k
 * @return {number}
 */
var minDays = function (bloomDay, m, k) {
    function helper(bloomDay, mid, m, k) {
        // mid=12
       
        const temp = []
        for (let i = 0; i < bloomDay.length; i++) {
            if (bloomDay[i] <= mid) {
                temp.push(1)
            }
            else {
                temp.push(-1)
            }
        }

        let final = 0;
        let count = 0;
        for (let i = 0; i < bloomDay.length; i++) {
            

            if (bloomDay[i] <= mid) {
                count++;
                if(count==k){
                    final++;
                    count=0;
                }

            }
            else {
                if (count == k) {
                    final++;

                }
                count = 0;
            }

        }
        if (count == k) {
            final++;

        }
        return final

    }
    let low = 1;
    let high = Math.max(...bloomDay);
    let res = -1;
    while (low <= high) {
        let mid = Math.floor((low + high) / 2);
        if (helper(bloomDay, mid, m, k) == m) {
            res = mid;
            high = mid - 1;

        }
        else if (helper(bloomDay, mid, m, k) > m) {
            high = mid - 1

        }
        else {
            low = mid + 1;
        }
    }
    return res

};