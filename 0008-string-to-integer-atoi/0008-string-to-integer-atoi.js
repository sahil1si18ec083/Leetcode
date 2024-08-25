/**
 * @param {string} s
 * @return {number}
 */
var myAtoi = function (s) {
    let result = 0;
    let signpositive = true;
    if (s.length == 0) {
        return 0;
    }
    while (s[0] == " ") {
        s = s.slice(1)
    }
    console.log(s)
    let j = 0;

    if (s[0] == "-") {
        signpositive = false;

        j++;
    }
    if (s[0] == "+") {


        j++;
    }
    for (let i = j; i < s.length; i++) {


        if (s.charCodeAt(i) >= 48 && s.charCodeAt(i) <= 57) {
            console.log({ result })
            result = result * 10 + (s.charCodeAt(i) - 48);
            let resultwithsign = signpositive ? result : result * -1;
            if (resultwithsign > Math.pow(2, 31) - 1) {
                return Math.pow(2, 31) - 1
            }
            if (resultwithsign < -Math.pow(2, 31)) {
                return -Math.pow(2, 31)

            }

        }
        else {
            console.log("h")
            break;
        }

    }

    return (signpositive ? result : result * -1)




};