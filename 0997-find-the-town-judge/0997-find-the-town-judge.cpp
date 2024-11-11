class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {

        vector<int>balance(n+1, 0);
        for(int i=0;i<trust.size();i++){
            int u= trust[i][0];
            int v = trust[i][1];
            balance[v]++;
            balance[u]--;
        }
        for(int i=1;i<=n;i++){
            if (balance[i]==n-1){
                return i;
            }
        }
        return -1;
        
    }
};