/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    class Stack {
    constructor(array) {
        this.array = array;
    }
    push(value) {
        this?.array?.push(value);
    }
    pop() {
        this?.array?.pop();
    }
    get top() {
        return this.array[this.array.length - 1];
    }
    get length() {
        return this?.array?.length;
    }
}
const myStack = new Stack([]);
for(let i=0;i<s.length;i++){
    if (myStack.length==0 && (s[i]==")" || s[i]=="}" || s[i]=="]" )){
        return false;
    }
    if ((s[i]==")" && myStack.top=="(") || (s[i]=="]" && myStack.top=="[") || (s[i]=="}" && myStack.top=="{")  ){
        myStack.pop()
    }
    else{
        myStack.push(s[i])
    }
}
console.log(myStack)
if (myStack.length===0){
    return true;
}
else{
    return false;
}

}; 