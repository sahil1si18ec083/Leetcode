class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s==goal) return true;
        if(s.size()!=goal.size()) return false;
        string temp = s+s;
        int n = goal.size();
        for(int i=0;i<n;i++){
            if(temp.substr(i,n)==goal){
                return true;
            }
        }
        return false;
    }
};


