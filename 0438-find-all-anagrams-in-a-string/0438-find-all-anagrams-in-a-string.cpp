class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;

        map<int, int> mymap;
        for (int i = 0; i < p.size(); i++) {
            mymap[p[i]]++;
        }
        int zeroscount = mymap.size();
        int k = p.size();
        for (int i = 0; i < k; i++) {
            if (mymap.find(s[i]) != mymap.end()) {
                mymap[s[i]]--;
                if (mymap[s[i]] == 0) {
                    zeroscount--;
                }
            }
        }
        if (zeroscount == 0) {
            result.push_back(0);
        }
        int i = 0;
        int j = k - 1;
        int n = s.size();
        while (j < n - 1) {
            j++;
            if (mymap.find(s[j]) != mymap.end()) {
                mymap[s[j]]--;
                if (mymap[s[j]] == 0) {
                    zeroscount--;
                }
            }
            if (mymap.find(s[i]) != mymap.end()) {
                mymap[s[i]]++;
                if (mymap[s[i]] == 1) {
                    zeroscount++;
                }
            }
            i++;
            if (zeroscount == 0) {
                result.push_back(i);
            }
        }

        return result;
    }
};