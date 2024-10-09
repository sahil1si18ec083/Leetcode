class Solution {
public:
    int minAddToMakeValid(string s) {

        stack<char> mystack;

        for (int i = 0; i < s.size(); i++) {
            if (mystack.empty()) {
                mystack.push(s[i]);
            } else {
                if (s[i] == ')' && mystack.size() > 0 && mystack.top() == '(') {
                    mystack.pop();
                } else {
                    mystack.push(s[i]);
                }
            }
        }
        return mystack.size();
    }
};