/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {

    let maxprofit=0;
       const n = prices.length;
    let maxarr= new Array(n).fill(0);
 
    for(let i= n-1;i>=0;i--){
        if(prices[i]>maxprofit){
            maxprofit= prices[i];

        }
        maxarr[i]= maxprofit;

    }
    let ans=0;
    for(let i=0;i<n;i++ ){
        let diff = maxarr[i]- prices[i];
        if(diff>ans){
            ans = diff;
        }
    }
    return ans;
    
};