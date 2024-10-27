class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;
        while (j > i) {
            if (isalnum(s[i]) && isalnum(s[j])) {
                if (tolower(s[i]) == tolower(s[j])) {
                    i++;
                    j--;
                } else {
                    return false;
                }
            } else if (isalnum(s[i])) {
                j--;
            } else if (isalnum(s[j])) {
                i++;
            } else {
                j--;
            }
        }
        return true;
    }
};