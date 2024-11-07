class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int maxresult=0;
        int n = candidates.size();
        
        for(int j=0;j<32;j++){
            // check if ith bit is set or not
            int count=0;
            for(int i=0;i<n;i++){
                int bit  = candidates[i]>>j;
                if((bit & 1)==1 ){
                    count++;
                }

            }
            maxresult= max(maxresult, count);
        }
        return maxresult;

    }
};