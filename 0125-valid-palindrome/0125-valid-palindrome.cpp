class Solution {
public:
    bool isalpha(char c) {
        int val = c;
        if (val >= 65 && val <= 90)
            return true;
        if (val >= 97 && val <= 122)
            return true;
        if (val >= 48 && val <= 57)
            return true;
        return false;
    }
    bool isPalindrome(string s) {
        int n = s.size();
        int i = 0;
        int j = n - 1;
        while (j > i) {
            if (isalpha(s[i]) && isalpha(s[j])) {
                int a = s[i];
                int b = s[j];
                int diff = b - a;
                cout<<a<<" a"<<b<<" b"<<endl;
                if(a==b){
                    i++;
                    j--;
                }
                else if (((a>=48 && a<=57)|| (b>=48 && b<=57))){
                    return false;
                }
               else  if (diff == 32 || diff == -32 || diff == 0) {
                    i++;
                    j--;
                } else {
                    return false;
                }
            } else if (isalpha(s[i])) {
                j--;
            } else if (isalpha(s[j])) {
                i++;
            } else {
                i++;
                j--;
            }
        }

        return true;
    }
};