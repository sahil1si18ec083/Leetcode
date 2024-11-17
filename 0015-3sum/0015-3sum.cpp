class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        int i=0;
        while(i<n-2){
            int j=i+1;
            int k=n-1;
            while(j<k){
                if (nums[i]+ nums[j]+ nums[k]==0){
                    vector<int>temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    res.push_back(temp);
                   
                    while(j<n-2 && nums[j]==nums[j+1]){
                        j++;

                    }
                    while(k>0 && nums[k]==nums[k-1]){
                        k--;

                    }
                    while( i<n-3 &&  nums[i]==nums[i+1]){
                        i++;

                    }
                     j++;
                    k--;

                }
                else if (nums[i]+ nums[j]+ nums[k]<0){
                    j++;
                }
                else{
                    k--;
                }
            }
            i++;
        }

        return res;

        
    }
};