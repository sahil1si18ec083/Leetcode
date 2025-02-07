class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int>res;

        unordered_map<int, int> mp;
        set<int> myset;
        int n = queries.size();
        for(int i=0;i<n;i++){
            int u = queries[i][0];
            int v = queries[i][1];
            if(mp.find(u)!=mp.end()){
                int oldvalue = mp[u];
                mp[u]= v;
                myset.erase(oldvalue);
                myset.insert(v);
            }
            else{
                mp[u]= v;
                myset.insert(v);
            }
            res.push_back(myset.size());
        }

        return res;
        
    }
};