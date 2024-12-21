/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function (s) {
    if (s.length == 0) return true;
    const stack = [];
    for (let i = 0; i < s.length; i++) {
        if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
            if (stack.length == 0) {
                return false;
            }
            if (s[i] == ")" && stack[stack.length - 1] == "(") {
                stack.pop();
            }
            else if (s[i] == "]" && stack[stack.length - 1] == "[") {
                stack.pop();
            }
            else if (s[i] == "}" && stack[stack.length - 1] == "{") {
                stack.pop();
            }
            else {
                stack.push(s[i]);
            }
        }
        else {
            stack.push(s[i]);
        }
    }

    if (stack.length == 0) return true;

    return false;




};