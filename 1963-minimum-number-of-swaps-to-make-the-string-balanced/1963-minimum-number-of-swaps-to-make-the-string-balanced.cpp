class Solution {
public:
    int minSwaps(string s) {
        stack<char> mystack;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '[') {
                mystack.push(s[i]);
            } else {
                if (!mystack.empty() && mystack.top() == '[') {
                    mystack.pop();
                }
            }
        }
        cout<<mystack.size();
        return (floor(1+mystack.size())/2);
    }
};