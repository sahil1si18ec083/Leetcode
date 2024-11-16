class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>mydeque;
        vector <int>result;
        int n = nums.size();

        for(int i=0;i<k;i++){
            while(!mydeque.empty() && nums[mydeque.back()]<=nums[i]){
                mydeque.pop_back();
            }
            mydeque.push_back(i);
        }
        result.push_back(nums[mydeque.front()]);
        int i=0;
        int j=k-1;
        while(j<n-1){
            if (i==mydeque.front()){
                mydeque.pop_front();
            }
            i++;
            j++;
             while(!mydeque.empty() && nums[mydeque.back()]<=nums[j]){
                mydeque.pop_back();
            }
            mydeque.push_back(j);
            result.push_back(nums[mydeque.front()]);

        }
        return result;

        
    }
};