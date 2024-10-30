class Solution {
public:
    int findPairs(vector<int>& arr, int k) {
        map<int, int> mymap;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
           mymap[arr[i]]++;
        }
        int res=0;
        for(auto i:mymap){
            if(i.second>1){
                res++;
            }
        }

        if(k==0){
            return (res);
        }
        
        int count = 0;
        for(auto i:mymap){
            if(mymap.find(i.first+k)!=mymap.end()){
                count++;
            }
            if(mymap.find(i.first-k)!=mymap.end()){
                count++;
            }
        }
        return count/2;
    }
};