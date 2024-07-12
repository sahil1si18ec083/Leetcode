/**
 * @param {number[]} tokens
 * @param {number} power
 * @return {number}
 */
var bagOfTokensScore = function (tokens, power) {
    const n = tokens.length;

    tokens.sort((a, b) => a - b);
    console.log({ tokens })
    let score = 0;
    let maxscore = 0;
    let i = 0;
    let j = n - 1;

    while (i <= j) {
        if (power >= tokens[i]) {
            power = power - tokens[i];
            score++;
            maxscore = Math.max(maxscore, score);
            i++;
        }
        else if (score >= 1) {
            power = power + tokens[j];
            j--;
            score--;


        }
        else{
            return maxscore
        }

    }
    return maxscore

   
};