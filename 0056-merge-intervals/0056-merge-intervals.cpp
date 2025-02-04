class Solution {
    
public:
     static bool mycomparator(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];  // Corrected comparison
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(), mycomparator);
        int n = intervals.size();
        vector<vector<int>> result;
        result.push_back(intervals[0]);

        for (int i = 1; i < n; i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            if (start > result[result.size() - 1][1]) {
                result.push_back({start,end});

            }
            else{
                result[result.size()-1][1]= max(result[result.size()-1][1], end);
            }
        }
        return result;
    }
};