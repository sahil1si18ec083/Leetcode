class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int total = 0;

        vector<int>leftmax(n,0);

        vector<int>rightmax(n,0);
        int lmaxvalue=0;
        int rmaxvalue=0;

        for(int i=0;i<n;i++){
            leftmax[i]= lmaxvalue;
            lmaxvalue= max(lmaxvalue, height[i]);

        }

        for(int i=n-1;i>=0;i--){
            rightmax[i]= rmaxvalue;
            rmaxvalue= max(rmaxvalue, height[i]);

        }

        for(int i=1;i<n-1;i++){

            total = total + ((  min(leftmax[i], rightmax[i]))- height[i] > 0
                                 ? min(leftmax[i], rightmax[i]) - height[i] 
                                 : 0);

        }

        
        return total;
    }
};