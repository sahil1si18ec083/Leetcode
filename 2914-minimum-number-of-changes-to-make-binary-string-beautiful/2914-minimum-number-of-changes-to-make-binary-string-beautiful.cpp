class Solution {
public:
    int minChanges(string s) {
        int minchnages = INT_MAX;
        int count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                count++;
            }
        }
        minchnages= min(minchnages , count);
        count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                count++;
            }
        }
        minchnages= min(minchnages , count);
        return minchnages;
    }
};