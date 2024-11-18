class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> res(n, 0);
        if (k == 0)
            return res;
        if (k > 0) {
            int val = 0;
            for (int it = 1; it <= k; it++) {
                val += code[it % n];
            }
            res[0] = val ;
            int i = 1;
            int j = k;
            // i=3 j=0

            for (int it = 1; it < n; it++) {
                val = val - code[i];
                i = (i + 1) % n;
                j = (j + 1) % n;
                 val = val + code[j];
                res[it] = val ;
            }
            return res;
        } else {
           
            int val = 0;
            for (int it = -1; it >= k; it--) {
                val += code[(it + n) % n];
            }
            
            res[0] = val ;
            int i = k;
            int j = -1;

            for (int it = 1; it < n; it++) {
                val = val - code[(i + n) % n];
                i = (i + 1 + n) % n;
                j = (j + 1 + n) % n;
                val = val + code[(j + n) % n];
                res[it] = val ;
            }
            return res;
        }
    }
};