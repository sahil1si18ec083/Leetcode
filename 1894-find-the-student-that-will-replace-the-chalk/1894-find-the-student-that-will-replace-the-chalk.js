/**
 * @param {number[]} chalk
 * @param {number} k
 * @return {number}
 */
var chalkReplacer = function(chalk, k) {
    const chalksum = chalk.reduce((acc,current)=>acc+current,0);
    k=k%chalksum;
    if (k==0){
        return 0;
    }
    let i=0;
    while(k>0){
      k= k- chalk[i];
      if(k>=0){
        i++;
      }
      else{
        return i;
      }
    }
    return i;
    
};