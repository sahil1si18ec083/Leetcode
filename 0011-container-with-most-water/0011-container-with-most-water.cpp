class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int low = 0;
        int high = n - 1;
        int maxarea = 0;
        while (low < high) {
            maxarea =
                max(maxarea, ((high - low) * min(height[low], height[high])));
            if (height[low] < height[high]) {

                low++;

            } else {
                high--;
            }
        }
        return maxarea;
    }
};