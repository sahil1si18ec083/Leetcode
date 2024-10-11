class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        // this will declare a  min heap and initialise a  nums vector

        for (int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]); // insert new one and remove the root so that size
                              // k is maintained
            if (pq.size() > k) {
                pq.pop();
            }
        }
        return pq.top();
    }
};