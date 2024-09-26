class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i=0;
        int j=0;
        int m = g.size();
        int n = s.size();
        int count=0;
        while(i<m && j<n){
            if (g[i]<=s[j]){
                count++;
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        return count;
    }
};