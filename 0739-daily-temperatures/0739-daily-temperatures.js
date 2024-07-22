/**
 * @param {number[]} temperatures
 * @return {number[]}
 */
var dailyTemperatures = function(temperatures) {
     const res=new Array(temperatures.length).fill(0);
        const myStack=[]
        for(let i=temperatures.length-1;i>=0;i--){
            while(myStack.length>0 && temperatures[myStack[myStack.length-1]]<=temperatures[i]){
                myStack.pop()
            }
            if (myStack.length>0 && temperatures[myStack[myStack.length-1]]>temperatures[i]){
                res[i]= myStack[myStack.length-1]-i
            }
            myStack.push(i)
        }
        return res
    
};