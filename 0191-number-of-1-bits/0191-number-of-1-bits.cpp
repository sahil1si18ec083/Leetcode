class Solution {
public:
    int hammingWeight(int n) {
        int res=0;
        while(n!=0){
            int rem = n & 1;
            res+=rem;
            n = n>>1;
        }
        return res;
        
    }
};