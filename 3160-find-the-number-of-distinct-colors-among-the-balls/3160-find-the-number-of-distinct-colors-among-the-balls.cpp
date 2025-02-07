class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int>res;

        unordered_map<int, int> mp;
       unordered_map<int, int> myset;
        int n = queries.size();
        for(int i=0;i<n;i++){
            int u = queries[i][0];
            int v = queries[i][1];
            if(mp.find(u)!=mp.end()){
                int oldvalue = mp[u];
                mp[u]= v;
                if(myset[oldvalue]==1){
                    myset.erase(oldvalue);
                }
                else{
                     myset[oldvalue]--;
                }
               myset[v]++;
            }
            else{
                mp[u]= v;
                myset[v]++;
                
            }
            res.push_back(myset.size());
        }

        return res;
        
    }
};