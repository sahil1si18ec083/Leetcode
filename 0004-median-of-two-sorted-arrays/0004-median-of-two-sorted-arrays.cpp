class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if(m>n){
            return findMedianSortedArrays(nums2, nums1);
        }
        int total = m + n;

        int low = 0;
        int high = m;

        while (low <= high) {
            int mid = (low + high) / 2;
            int x = (m + n + 1) / 2 - mid;
            int l1 = (mid < 1 ? INT_MIN : nums1[mid - 1]);
            int l2 = (x < 1 ? INT_MIN : nums2[x - 1]);
            int r1 = (mid >= m ? INT_MAX : nums1[mid]);
            int r2 = (x >= n ? INT_MAX : nums2[x]);
            if (r1 >= l2 && r2 >= l1) {
                if (total %2==1){
                    int val = max(l1,l2);
                    return(double) (val);

                }
                else{
                    int sum = max(l1,l2 ) + min(r1, r2);
                    return ((double(sum)/ double(2)));


                }

            } else if (l1 < r2) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return 0.00000;
    }
};