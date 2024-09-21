/**
 * @param {number} n
 * @return {number[]}
 */
var lexicalOrder = function (n) {
    const arr = []
    for (let i = 1; i <= n; i++) {
        arr.push(i)
    }

    arr.sort((a, b) => {
        let stringa = String(a)
        let stringb = String(b)
        const m = stringa.length;
        const n = stringb.length;
        let i = 0;
        let j = 0;
        while (i < m && j < n) {
            if (stringa.charCodeAt(i) === stringb.charCodeAt(j)) {
                i++;
                j++;
            }
            else if (stringa.charCodeAt(i) > stringb.charCodeAt(j)) {
                return 1
            }
            else {
                return -1;
            }
        }
        while (i < m) {
            return 1;

        }
        while (j < n) {
            return -1
        }
    })



    return arr

};