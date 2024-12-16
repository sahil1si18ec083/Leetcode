class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {

        priority_queue<pair<long long, long long>>pq;
        int n = gifts.size();
        for(long long i=0;i<n;i++){
            pq.push({ gifts[i],i});
        }
        long long res =0;

        for(long long i=0;i<k;i++){

            pair<long long, long long>p= pq.top();
            long long val = p.first;
            long long index = p.second;
            pq.pop();
            pq.push({ sqrt(val),index});
        }
        while(!pq.empty()){
            pair<long long, long long>p= pq.top();
             long long val = p.first;
             

        }

        return res;
        
    }
};