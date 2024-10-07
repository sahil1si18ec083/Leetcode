class Solution {
public:
    int minLength(string s) {
        stack<char> mystack;
        mystack.push(s[0]);
        for (int i = 1; i < s.size(); i++) {

            if (mystack.empty()) {
                mystack.push(s[i]);
            } else {
                if ((mystack.top()=='A' && s[i]=='B')||  (mystack.top()=='C' && s[i]=='D')) {
                    mystack.pop();
                } else {
                    mystack.push(s[i]);
                }
            }
        }
        // while (mystack.size() > 1) {
        //     char top = mystack.top();
        //     mystack.pop();
        //     char secondtop = mystack.top();
        //     if ((secondtop == 'A' && top == 'B') ||
        //         (secondtop == 'C' && top == 'D')) {
        //         mystack.pop();
        //     } else {
        //         mystack.push(top);
        //         break;
        //     }
        // }
        return mystack.size();
    }
};