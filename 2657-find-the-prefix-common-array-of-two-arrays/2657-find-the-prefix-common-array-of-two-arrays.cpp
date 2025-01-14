class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int count = 0;
        set<int> st;
        int n = A.size();
        vector<int>result;

        for (int i = 0; i < n; i++) {
            if (st.find(A[i]) != st.end()) {
                count++;
            }
            st.insert(A[i]);
            if (st.find(B[i]) != st.end()) {
                count++;
            }
            st.insert(B[i]);
            result.push_back(count);
        }
        return result;
    }
};