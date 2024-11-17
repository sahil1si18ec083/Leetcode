class Solution {
public:
    bool isValid(int i, int j, vector<int>& nums) {
        // O(1) MAI CHAL RAHA HAI
        if (j == i)
            return true;
        if(j-i==1 && nums[j]-nums[i]==1){
            return true;
        }
        if(j-i>1 && nums[j]-nums[j-2]==0){
            return true;
        }
        return false;
    }
    int alternatingSubarray(vector<int>& nums) {
        int maxlength = INT_MIN;
        int length = 0;
        int i = 0;
        int j = 0;
        int n = nums.size();
        while (j < n) {

            while(!(isValid(i,j,nums))){
                i++;
                length--;
            }
            length++;
            maxlength= max(maxlength, length);
            j++;

        }
        if (maxlength>1) return maxlength;

        return -1;
    }
};