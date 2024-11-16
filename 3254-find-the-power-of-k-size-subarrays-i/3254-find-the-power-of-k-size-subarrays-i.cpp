class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        list<int> dq;
        int n = nums.size();
        vector<int> result;
        for (int i = k - 1; i >= 0; i--) {
            if (dq.size() == 0) {
                dq.push_front(i);
            } else {
                if (nums[dq.front()] - nums[i] == 1) {
                    dq.push_front(i);
                }
            }
        }

        if (dq.size() == k) {
            result.push_back( nums[dq.back()]);
        } else {
            result.push_back(-1);
        }
        int i = 0;
        int j = k - 1;
        while (j < n - 1) {
            if (i == dq.front()) {
                dq.pop_front();
            }
            i++;
            j++;
            if (dq.size() == 0) {
                dq.push_back(j);
            } else if (nums[j] - nums[dq.back()] == 1) {
                dq.push_back(j);

            } else {
                while (dq.size() > 0) {
                    dq.pop_back();
                }
                dq.push_back(j);
            }
            if (dq.size() == k) {
                result.push_back(nums[dq.back()]);
            } else {
                result.push_back(-1);
            }
        }

        return result;
    }
};