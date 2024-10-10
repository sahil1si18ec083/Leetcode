class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue <int> myPQ;

        for(int i=0;i<nums.size();i++){
            myPQ.push(nums[i]);
        }
        for(int i=1;i<k;i++){
            myPQ.pop();
        }

        return myPQ.top();
    }
};