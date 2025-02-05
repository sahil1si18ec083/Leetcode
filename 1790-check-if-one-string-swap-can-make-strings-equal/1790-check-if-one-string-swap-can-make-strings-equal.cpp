class Solution {
public:
    void swap(string& s, int i, int j) {
        char c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size();
        if (s1 == s2)
            return true;

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(s1, i, j);
                if (s1 == s2)
                    return true;
                swap(s1, i, j);
            }
        }

        return false;
    }
};