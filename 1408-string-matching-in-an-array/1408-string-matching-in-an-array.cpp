class Solution {
public:
    bool checksubstring(string s, string t) {
        int n = s.size();
        int m = t.size();
        cout << s << " |" << t << endl;
        if (n < m)
            return false;
        if (n == m && s == t)
            return true;
        for (int i = 0; i <= n - m; i++) {

            if (s.substr(i, m) == t) {
                return true;
            }
        }
        return false;
    }
    vector<string> stringMatching(vector<string>& words) {

        int n = words.size();
        set<string> res;
        vector<string> ans;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    if (checksubstring(words[i], words[j])) {
                        res.insert(words[j]);
                    }
                }
            }
        }
        for (auto i : res) {
            ans.push_back(i);
        }
        return ans;
    }
};