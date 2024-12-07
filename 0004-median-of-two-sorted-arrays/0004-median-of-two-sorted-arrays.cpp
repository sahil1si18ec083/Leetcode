class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        
        if(nums2.size()<nums1.size()){
            return findMedianSortedArrays(nums2, nums1);
        }
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = (n1 + n2);
        int low = 0;
        int high = n1;
        double val =0.00000;
        while (low <= high) {
            int mid = (low + high) / 2;
            int x = (n + 1) / 2 - mid;
            int l1 = mid ==0 ? INT_MIN : nums1[mid - 1];
            int l2 = x ==0 ? INT_MIN : nums2[x - 1];
            int r1 = mid == n1 ? INT_MAX : nums1[mid];
            int r2 = x == n2 ? INT_MAX : nums2[x];
            if (l1 <= r2 && l2 <= r1) {
                if (n % 2 == 0) {
                    int maxleft = max(l1,l2);
                    int minright = min(r1,r2);
                    return (double(maxleft+minright)/2);

                } else {
                     int maxleft = max(l1,l2);
                     return double(maxleft);
                }

            } else if (l1 >= r2) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return val;
    }
};