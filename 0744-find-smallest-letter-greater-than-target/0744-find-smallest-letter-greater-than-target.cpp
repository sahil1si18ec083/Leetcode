class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans = letters[0];
        int n = letters.size();
        int low = 0;
        int high = n - 1;
        while (low <= high) {
            int mid = (low) + (high - low) / 2;
            int midchatracter = (int)letters[mid];
            int targetch = (int)target;
            if (midchatracter > targetch) {
                ans = letters[mid];
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};