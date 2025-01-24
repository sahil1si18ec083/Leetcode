class Solution {
public:
    bool checkIfPangram(string sentence) {
        set<char> st;
        for(auto ch:sentence){
            st.insert(ch);

        }
        if(st.size()==26) return true;
        return false;
    }
};