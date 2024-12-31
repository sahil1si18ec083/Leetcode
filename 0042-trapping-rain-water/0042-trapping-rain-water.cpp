class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int total = 0;

        int left = 0;

        int right = n - 1;

        int leftmax = height[0];

        int rightmax = height[n - 1];

        while (left <= right) {

            if (height[left] <= height[right]) {
                // left sai paani lena padega
                if (leftmax <= height[left]) {
                    leftmax = height[left];
                } else {
                    total = total + leftmax - height[left];
                }
                left++;
            } else {
                if (rightmax <= height[right]) {
                    rightmax = height[right];
                } else {
                    total = total + rightmax - height[right];
                }
                right--;
            }
        }
        return total;

        return total;
    }
};