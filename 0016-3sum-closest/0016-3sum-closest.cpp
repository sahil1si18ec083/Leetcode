class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        int i=0;
        int minabs=INT_MAX;
        int res=0; 
        while(i<n-2){
            int j=i+1;
            int k=n-1;
            while(j<k){
                if (nums[i]+ nums[j]+ nums[k]==target){
                   return target;

                }
                else if (nums[i]+ nums[j]+ nums[k]< target){
                    int sum = nums[i]+ nums[j]+ nums[k];
                    if(abs(sum-target)<minabs){
                        res= sum;
                        minabs= abs(sum - target);
                    }
                    j++;
                }
                else{
                    int sum = nums[i]+ nums[j]+ nums[k];
                    if(abs(sum-target)<minabs){
                        res= sum;
                        minabs= abs(sum - target);
                    }
                    k--;
                }
            }
            i++;
        }


        return res;
    }
};