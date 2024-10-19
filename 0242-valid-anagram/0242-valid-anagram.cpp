class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int>mymap;
        for(int i=0;i<s.size();i++){
            mymap[s[i]]++;
        }
        for(int i=0;i<t.size();i++){
            mymap[t[i]]--;
        }
        for (auto i:mymap){
            if(i.second!=0){
                return false;
            }
        }
        for (auto i:mymap){
            i.second =0;
        }
        for(int i=0;i<s.size();i++){
            mymap[t[i]]++;
        }
        for(int i=0;i<s.size();i++){
            mymap[s[i]]--;
        }
        for (auto i:mymap){
            if(i.second!=0){
                return false;
            }
        }
        return true;
        
    }
};