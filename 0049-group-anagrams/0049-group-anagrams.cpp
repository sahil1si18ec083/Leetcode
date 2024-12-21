class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mymap;
        vector<vector<string>> result;
        int n = strs.size();
        for(int i=0;i<n;i++){
            string sortedvalue = strs[i];
            sort(sortedvalue.begin(), sortedvalue.end());
            mymap[sortedvalue].push_back(strs[i]);
        }
        for(auto i:mymap){
            result.push_back(i.second);
        }
        return result;
    }
};