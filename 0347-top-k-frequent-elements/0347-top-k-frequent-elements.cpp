class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // create a hashmap for  arr[i] vs count
        map<int, int> mymap;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        for (int i = 0; i < nums.size(); i++) {
            mymap[nums[i]]++;
        }
        for (auto i : mymap) {
            pq.push({i.second, i.first});
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector <int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};