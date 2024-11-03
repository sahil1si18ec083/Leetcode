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
    void helper(TreeNode* root, int& absval, int minval, int maxval) {
        if (root == NULL) {
            return;
        }
        minval = min(root->val, minval);
        maxval = max(root->val, maxval);
        if (root->left == NULL && root->right == NULL) {
            absval = max(abs(maxval - minval), absval);
            return;
        }
        helper(root->left, absval, minval, maxval);
        helper(root->right, absval, minval, maxval);
    }
    int maxAncestorDiff(TreeNode* root) {
        int absval = 0;
        int minval = root->val;
        int maxval = root->val;
        helper(root, absval, minval, maxval);
        return absval;
    }
};