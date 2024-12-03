class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {

        string res = "";
        int n = s.size();
        int m = spaces.size();

        int l = 0;

        for (int i = 0; i < n; i++) {
            if(i>spaces[m-1]){
                res+=s[i];
                continue;
            }

            if(spaces[l]!=i){
                res+=s[i];
            }
            else{
                res+=" ";
                l++;
                res+=s[i];
            }
        }
        return res;
    }
};