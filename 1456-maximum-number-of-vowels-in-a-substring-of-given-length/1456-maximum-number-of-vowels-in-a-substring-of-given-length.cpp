class Solution {
public:
    int maxVowels(string s, int k) {
        int res = 0;
        int n = s.size();
        map<char, int> mymap;
        mymap['a'] = 0;
        mymap['e'] = 0;
        mymap['i'] = 0;
        mymap['o'] = 0;
        mymap['u'] = 0;
        for (int i = 0; i < k; i++) {
            mymap[s[i]]++;
        }
        int val =
            mymap['a'] + mymap['e'] + mymap['i'] + mymap['o'] + mymap['u'];
        res = max(res, val);
        int i = 0;
        int j = k - 1;
        while (j < n - 1) {
            mymap[s[i]]--;
            i++;
            j++;
            mymap[s[j]]++;
            int val =
                mymap['a'] + mymap['e'] + mymap['i'] + mymap['o'] + mymap['u'];
            res = max(res, val);
        }
        return res;
    }
};