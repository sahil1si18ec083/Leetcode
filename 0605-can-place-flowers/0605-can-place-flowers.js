/**
 * @param {number[]} flowerbed
 * @param {number} n
 * @return {boolean}
 */
var canPlaceFlowers = function(flowerbed, n) {
    const l= flowerbed.length;
    if (flowerbed.length==0) return true
    if (l==1){
        if (n==1 && flowerbed[0]==0){
            return true
        }
        if(n==0){
            return true
        }
        return false
    }
    let i=0;

    while(i<l){
        console.log({i})
        if (i==0 && flowerbed[0]==0 &&   flowerbed[1]==0){
            i=i+2;
            n--;
        }
        else if (i==l-1 && flowerbed[i]==0 && flowerbed[i-1]==0){
            
            i=i+2;
            n--;
        }
        else if (flowerbed[i]==0 && flowerbed[i-1]==0 && flowerbed[i+1]==0){
            i=i+2
            n--;
        }
        else{
            i++
        }
    }
    console.log({n})
    if(n<=0){
        return true
    }  
    return  false
};