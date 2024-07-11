/**
 * @param {string} s
 * @return {string}
 */
     function reverse(s) {
        let x = ""
        for (let i = 0; i < s.length; i++) {
            x = s[i] + x;
        }
        return x;
    }
    function countofParentheses(s){
        let count=0;
       for(let i=0;i<s.length;i++){
        if (s[i]=="(" ||  s[i]==")"){
            count++;
        } 
       }
       return count
    }
var reverseParentheses = function (s) {

    if (countofParentheses(s)==2 && s[0]=="("  && s[s.length-1]==")") {
        return reverse(s.slice(1, s.length - 1))
    }
    if (countofParentheses(s)==0 && s[0]!="("  && s[s.length-1]!=")"){
        return s
    }
    let start = 0;
    let end = 0;
    for (let i = 0; i < s.length; i++) {
        if (s[i] == "(" && i != 0) {
            start = i;
        }
        if (s[i] == ")") {
            end = i;
            break;
        }
    }
    return reverseParentheses(s.slice(0, start) + reverseParentheses(s.slice(start, end + 1)) + s.slice(end + 1, s.length))
   

};