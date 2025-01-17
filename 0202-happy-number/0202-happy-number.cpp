class Solution {
public:
    int sumsquare(int val) {
        int res = 0;
        while (val != 0) {
            int rem = val % 10;
            res = res + rem * rem;
            val = val / 10;
        }
        return res;
    }
    bool isHappy(int n) {
        bool hasloop= false;
        int slow = n;
        int  fast = n;
        if(sumsquare(n)==1) return true;
        while(fast!=1){
            slow = sumsquare(slow);
            fast = sumsquare(sumsquare(fast));
            if(slow==fast){
                hasloop =  true;
                break;
            }
        }

        if(hasloop) return false;

        return true;

    }
};