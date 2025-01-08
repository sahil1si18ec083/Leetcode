class Solution {
public:
    bool isvalid(string a, string b) {
        int alength = a.size();
        int blength = b.size();
        if (alength > blength)
            return false;
            bool x = b.substr(0, alength)== a;
           cout<<x;
        if( b.substr(0, alength)== a &&    b.substr(blength- alength, alength)==a   )    {
            return true;
        }
        return false;  
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int count = 0;

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isvalid(words[i], words[j])) {
                    count++;
                }
            }
        }
        return count;
    }
};