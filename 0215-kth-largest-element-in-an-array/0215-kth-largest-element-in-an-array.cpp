class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue <int, vector <int>, greater <int> >pq(nums.begin(), nums.begin()+k);
        // this will declare a  min heap and initialise a  nums vector

        for(int i=k;i<nums.size();i++){
            pq.push(nums[i]); // insert new one and remove the root so that size k is maintained
            pq.pop();
            
        }
        return pq.top();
    }
};