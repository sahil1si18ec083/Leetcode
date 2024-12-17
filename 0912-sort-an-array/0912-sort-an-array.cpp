
class Solution {
public:
    void mergemethod(vector<int>& nums, int low, int mid, int high) {
        int i = low;
        int j = mid + 1;
        vector<int> temp;

        while (i <= mid && j <= high) {
            if (nums[i] <= nums[j]) {
                temp.push_back(nums[i]);
                i++;

            } else {
                temp.push_back(nums[j]);
                j++;
            }
        }
        while (i <= mid) {

            temp.push_back(nums[i]);
            i++;
        }
        while (j <= high) {

            temp.push_back(nums[j]);
            j++;
        }
        
        for(int it=0;it<temp.size();it++){
            nums[low]= temp[it];
            low++;
        }
    }
    void mergesort(vector<int>& nums, int low, int high) {

        if (low >= high) {
            return;
        }
        int mid = (low + high) / 2;

        mergesort(nums, low, mid);
        mergesort(nums, mid + 1, high);

        mergemethod(nums, low, mid, high);
    }

    vector<int> sortArray(vector<int>& nums) {

        int n = nums.size();

        mergesort(nums, 0, n - 1);

        return nums;
    }
};