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
    void solve(TreeNode* root, int& count, int maxval) {
        if (root == NULL) {
            return ;
        }
        // left call marunga
        if (root->val >= maxval) {
            count++;
        }
        solve(root->left, count, max(maxval, root->val));
        solve(root->right, count, max(maxval, root->val));
    }
    int goodNodes(TreeNode* root) {

        int count = 0;
        int maxval = INT_MIN;
        solve(root, count, maxval);
        return count;
    }
};