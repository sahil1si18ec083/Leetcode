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
    int counnodes(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        return (1 + counnodes(root->left) + counnodes(root->right));
    }
    int dfs(TreeNode* root, int& res) {
        if (root == NULL) {
            return 0;
        }
        if (root->left == NULL && root->right == NULL) {
            res += 1;
            return root->val;
        }
        int lsum = dfs(root->left, res);
        int rsum = dfs(root->right, res);
        int param = (lsum + rsum + root->val) / (counnodes(root));
        if (param == root->val) {
            res += 1;
        }
        return (root->val + lsum + rsum);
    }
    int averageOfSubtree(TreeNode* root) {
        int res = 0;
        int val = dfs(root, res);
        return res;
    }
};