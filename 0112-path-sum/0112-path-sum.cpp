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
    bool findsum(int sum, int targetSum, TreeNode* root) {
        
        if (root == NULL) {
            return false;
        }
        if (root->left == NULL && root->right == NULL &&
            sum + root->val == targetSum) {
            return true;
        }
        bool l = findsum(sum + root->val, targetSum, root->left);
        bool r = findsum(sum + root->val, targetSum, root->right);
        return (l || r);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {

        int sum = 0;
        return findsum(sum, targetSum, root);
    }
};