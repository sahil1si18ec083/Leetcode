class Solution {
public:
    static bool mycomparator(vector<int>& a, vector<int>& b) {
        return a[0] < b[0];
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {

        vector<vector<int>> res;

        intervals.push_back(newInterval);

        sort(intervals.begin(), intervals.end(), mycomparator);

        int n = intervals.size();
        if (n < 2) {
            return intervals;
        }

        res.push_back(intervals[0]);

        for (int i = 1; i < n; i++) {
            int firstval = res[res.size() - 1][0];
            int secondval = res[res.size() - 1][1];

            if (intervals[i][0] > secondval) {
                res.push_back(intervals[i]);
            } else {
                res.pop_back();
                vector<int> temp;
                temp.push_back(firstval);
                temp.push_back(max(secondval, intervals[i][1]));
                res.push_back(temp);
            }
        }
        return res;
    }
};