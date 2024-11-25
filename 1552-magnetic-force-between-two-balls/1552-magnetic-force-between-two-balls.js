/**
 * @param {number[]} position
 * @param {number} m
 * @return {number}
 */
var maxDistance = function (position, m) {

    function isValid(position, m, mid){
        let count=1;
        let prev = position[0]
        for(let i=1;i<position.length;i++){
            if (position[i]-prev>=mid){
                count++;
                prev = position[i]
            }

        }
        if(count<m){
            return false
        }
        return true
    }

    position.sort((a, b) => a - b);

    let low = 0;
    let high = position[position.length - 1] - position[0];
    let res;
    while (low <= high) {
        let mid = Math.floor((low + high) / 2);
        if (isValid(position, m, mid)) {
            low = mid + 1;
            res = mid;
        }
        else {
            high = mid - 1
        }
    }
    return res;
};