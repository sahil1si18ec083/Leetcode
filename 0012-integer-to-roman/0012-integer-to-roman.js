/**
 * @param {number} num
 * @return {string}
 */
var intToRoman = function (num) {
    let str = "";
    const map = new Map();
    map.set(1, "I");
    map.set(2, "II");
    map.set(3, "III");
    map.set(4, "IV");
    map.set(5, "V");
    map.set(6, "VI");
    map.set(7, "VII");
    map.set(8, "VIII");
    map.set(9, "IX");

    while (num != 0) {
        if (num >= 1000) {
            let f = Math.floor(num / 1000);
            num = num % 1000;
            for (let i = 0; i < f; i++) {
                str += "M";
            }
        }
        else if (num >= 900 && num <= 999) {
            num = num - 900;
            str = str + "C" + "M";
        }
        else if (num >= 500 && num <= 899) {
            num = num - 500;
            str = str + "D";
        }
        else if (num >= 400 && num <= 499) {
            num = num - 400;
            str = str + "C" + "D";
        }
        else if (num >= 100 && num <= 399) {
            let f = Math.floor(num / 100);
            num = num % 100;
            for (let i = 0; i < f; i++) {
                str += "C";
            }
        }
        else if (num >= 90 && num <= 99) {
            num = num - 90;
            str = str + "X" + "C";

        }
        else if (num >= 50 && num <= 89) {
            num = num - 50;
            str = str + "L";

        }
        else if (num >= 40 && num <= 49) {
            num = num - 40;
            str = str + "X" + "L";

        }

        else if (num >= 10 && num <= 39) {
            let f = Math.floor(num / 10);
            num = num % 10;
            for (let i = 0; i < f; i++) {
                str += "X";
            }
        }
        else if (map.has(num)) {

            str = str + map.get(num);
            num = 0;

        }


    }
    return str;

};