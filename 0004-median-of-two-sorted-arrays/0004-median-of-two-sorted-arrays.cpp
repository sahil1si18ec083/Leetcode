class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();
        int m = nums2.size();
        int low = 0;
        int high = n;
        double ans = 0.0;
        
         if (n > m) {
            return findMedianSortedArrays(nums2, nums1);
        }

        while (low <= high) {
            int i1 =
                (low + high) /
                2; // mid will be the number of elements in the left top side
            // i1==0
            int i2 = (n + m + 1) / 2 - i1;
            // i2=1
            int l1 = i1 == 0 ? INT_MIN : nums1[i1 - 1];
            int l2 = i2 == 0 ? INT_MIN : nums2[i2 - 1];
            int r1 = i1 == n ? INT_MAX : nums1[i1];
            int r2 = i2 == m ? INT_MAX : nums2[i2];
            if (l1 <= r2 && r1 >= l2) {
                if ((m + n) % 2 == 0) {

                    return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
                } else {
                    return max(l1, l2);
                }

            } else if (l1 >= r2) {
                high = i1 - 1;
            } else {
                low = i1 + 1;
            }
        }
        return ans;
    }
};