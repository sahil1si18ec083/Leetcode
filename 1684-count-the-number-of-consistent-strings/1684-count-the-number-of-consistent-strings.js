/**
 * @param {string} allowed
 * @param {string[]} words
 * @return {number}
 */
var countConsistentStrings = function (allowed, words) {
    function setIthbit(atwhichbit, number) {
        return (number | (1 << atwhichbit))
    }
    function checkithbitiset(i,number){
        return (1& (number>>i))
    }
    var number = 0;
    for (let i = 0; i < allowed.length; i++) {
        let atwhichbit = allowed.charCodeAt(i) - 97;
        number = setIthbit(atwhichbit, number)
    }
    var count = 0;
    for (let i = 0; i < words.length; i++) {
        var flag = true;
        for (let j = 0; j < words[i].length; j++){
            if (checkithbitiset(words[i].charCodeAt(j)-97, number)==false){
                flag = false;

            }
        }
        count = count + Boolean(flag)

    }

    return count
};