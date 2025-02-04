class Solution {
public:
    static bool comparator(vector<int> a, vector<int> b) { return a[0] < b[0]; }
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {

        intervals.push_back(newInterval);
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end(), comparator);
        result.push_back(intervals[0]);
        int n = intervals.size();
        for (int i = 1; i < n; i++) {
            int s = intervals[i][0];
            int e = intervals[i][1];
            if (s > result[result.size() - 1][1]) {
                result.push_back({s, e});
            } else {
                result[result.size() - 1][1] =
                    max( result[result.size() - 1][1], e);
            }
        }
        return result;
    }
};