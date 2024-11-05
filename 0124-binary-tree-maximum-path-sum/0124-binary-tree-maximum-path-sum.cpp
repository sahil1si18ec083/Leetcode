/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int helper(int& maxsum, TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int leftsum = helper(maxsum,root->left);
        int rightsum = helper(maxsum,root->right);
        if (leftsum < 0) {
            leftsum = 0;
        }
        if (rightsum < 0) {
            rightsum = 0;
        }
        int possiblemaxsum = leftsum + rightsum + root->val;
        maxsum = max(maxsum, possiblemaxsum);
        return (root->val + max(leftsum, rightsum));
    }
    int maxPathSum(TreeNode* root) {

        int maxsum = INT_MIN;

        int sum = helper(maxsum, root);

        return maxsum;
    }
};