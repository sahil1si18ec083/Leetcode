class Solution {
public:
    static bool comparator(vector<int> a, vector<int> b) { return a[0] < b[0]; }
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {

        int index = 0;
        for (int i = 0; i < intervals .size(); i++) {
            if (intervals [i][0] < newInterval[0]) {
                index = i+1;
                
            }
        }
        intervals.insert(intervals.begin() + index, newInterval);

        vector<vector<int>> result;
        result.push_back(intervals[0]);
        cout<<intervals[0][0];

        int n = intervals.size();
        for (int i = 1; i < n; i++) {
            int s = intervals[i][0];
            int e = intervals[i][1];
            if (s > result[result.size() - 1][1]) {
                result.push_back({s, e});
            } else {
                result[result.size() - 1][1] =
                    max(result[result.size() - 1][1], e);
            }
        }
        return result;
    }
};