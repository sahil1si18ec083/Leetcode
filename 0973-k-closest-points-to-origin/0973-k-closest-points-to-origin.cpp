class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        // take a max heap and if it crosses size k, then pop it

        int n = points.size();

        priority_queue<pair<int, int>> pq;

        for(int i=0;i<n;i++){
            int x = points[i][0];
            int y = points[i][1];
            int mag = x * x + y * y;
            pq.push({ mag, i});

            if(pq.size()>k){
                pq.pop();
            }

        }

        vector<vector<int>>result;

        while(pq.size()>0){
            pair<int, int> p = pq.top();
            vector<int>temp;
            temp.push_back(points[p.second][0]);
            temp.push_back(points[p.second][1]);
            result.push_back(temp);

            k--;


            pq.pop();
        }

        return result; 
    }
};