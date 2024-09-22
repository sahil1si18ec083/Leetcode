/**
 * @param {number[]} players
 * @param {number[]} trainers
 * @return {number}
 */
var matchPlayersAndTrainers = function(players, trainers) {
    players.sort((a,b)=>a-b)
    trainers.sort((a,b)=>a-b)
    let i=0;
    let j=0;
    while(j<trainers.length && i<players.length){
        if (trainers[j]>=players[i]){
            i++;
            j++;
        }
        else{
            j++;
        }
    }
  return i;
    
};