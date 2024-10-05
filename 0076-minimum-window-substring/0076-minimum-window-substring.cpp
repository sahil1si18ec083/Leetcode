class Solution {
public:
    string minWindow(string s, string t) {
        if (s == t) {
            return s;
        }
        

        int minval = INT_MAX;
        int startindex = -1;
        map<char, int> myMap;
        int zerocount = 0;
        int m = s.size();
        int n = t.size();
        if(m<n){
            return "";
        }
        for (int i = 0; i < n; i++) {
            myMap[t[i]]++;
        }
        int required = myMap.size();
        int i = 0;
        int j = 0;
        while (j < m) {
            if (myMap.find(s[j]) != myMap.end()) {
                myMap[s[j]]--;
                if (myMap[s[j]] == 0) {
                    zerocount++;
                }
            }
           
            while (zerocount == required) {

                if (j - i+1 < minval) {
                    minval = j - i+1;
                    startindex=i;
                }

                if (myMap.find(s[i]) != myMap.end()) {
                    myMap[s[i]]++;
                    if (myMap[s[i]] > 0) {
                        zerocount--;
                    }
                }
                i++;
            }

            j++;
        }
     
        return s.substr(startindex,minval);
    }
};