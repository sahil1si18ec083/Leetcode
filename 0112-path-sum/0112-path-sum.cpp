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
    void solve(TreeNode* root, int targetSum, int sum, bool& flag) {
        if (root == NULL) {
            return;
        }

        if (root->left == NULL && root->right == NULL) {
            if (sum + root->val == targetSum) {
                flag = true;
            }
            return;
        }
        // left path explore karo
        solve(root->left, targetSum, sum + root->val, flag);
        // right path karo
        solve(root->right, targetSum, sum + root->val, flag);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool flag = false;
        int sum = 0;
        solve(root, targetSum, sum, flag);

        return flag;
    }
};