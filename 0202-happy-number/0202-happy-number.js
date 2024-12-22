/**
 * @param {number} n
 * @return {boolean}
 */
var square= function(n){
    let res =0;
    while(n!=0){
        let rem = n % 10;
        res = res + rem*rem;
        n=Math.floor(n/10);
    }
    return res;
} 
var isHappy = function(n) {
    let slow= n;
    let  fast = n;
    while(1){
        slow = square(slow);
        fast = square(square(fast));
        if(fast==1){
            return true;
        }
        if(slow==fast){
            return false;
        }
    }
    return false;
    
};