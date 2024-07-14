
var StockSpanner = function() {
    this.myStack=[];
    this.priceArraylength=0;
    
};

/** 
 * @param {number} price
 * @return {number}
 */
StockSpanner.prototype.next = function(price) {
    
    var result = this.priceArraylength+1;
    while(this.myStack.length>0 && this.myStack[this.myStack.length-1].value<=price){
        this.myStack.pop()
    }
    if (this.myStack.length>0 && this.myStack[this.myStack.length-1].value>price){
        result = this.priceArraylength- this.myStack[this.myStack.length-1].key;
    }

    this.myStack.push({
        key: this.priceArraylength,
        value: price
    })
    this.priceArraylength= this.priceArraylength + 1;
    
    return result
};

/** 
 * Your StockSpanner object will be instantiated and called as such:
 * var obj = new StockSpanner()
 * var param_1 = obj.next(price)
 */