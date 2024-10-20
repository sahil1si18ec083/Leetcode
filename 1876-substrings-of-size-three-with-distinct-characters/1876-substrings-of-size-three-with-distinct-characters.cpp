class Solution {
public:
    int countGoodSubstrings(string s) {

        int result = 0;
        int n = s.size();
        if (n < 3) {
            return 0;
        }
        map<char, int> mymap;
        // first check the first window of size 3
        for (int i = 0; i < 3; i++) {
            mymap[s[i]]++;
        }
        if (mymap.size() == 3) {
            result++;
        }
        int i = 0;
        int j = 2;
        while (j < n - 1) {
            mymap[s[i]]--;
            if (mymap[s[i]] == 0) {
                mymap.erase(s[i]);
            }

            i++;
            j++;
            mymap[s[j]]++;
            if (mymap.size() == 3) {
                result++;
            }
        }
        return result;
    }
};