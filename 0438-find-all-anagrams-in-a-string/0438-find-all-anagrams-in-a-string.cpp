class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        int n = s.size();
        map<char, int> mymap;
        int zeroscount = 0;
        for (int i = 0; i < p.size(); i++) {
            mymap[p[i]]++;
        }
        int mapsize = mymap.size();
        int m = p.size();
        if (m > n) {
            return result;
        }
        for (int i = 0; i < m; i++) {
            mymap[s[i]]--;
            if (mymap[s[i]] == 0) {
                zeroscount++;
            } else if (mymap[s[i]] == -1)
                zeroscount--;
        }
        if (zeroscount == mapsize) {
            result.push_back(0);
        }
        int i = 0;
        int j = m - 1;

        while (j < n - 1) {
            cout << "hello";
            mymap[s[i]]++;
            if (mymap[s[i]] == 1) {
                zeroscount--;
            } else if (mymap[s[i]] == 0) {
                zeroscount++;
            }
            i++;
            j++;
            mymap[s[j]]--;
            if (mymap[s[j]] == -1) {
                zeroscount--;
            } else if (mymap[s[j]] == 0) {
                zeroscount++;
            }

            if (zeroscount == mapsize) {
                result.push_back(i);
            }
        }
        return result;
    }
};