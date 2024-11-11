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
    pair<int, int> dfs(TreeNode* root, int& res) {
        if (root == NULL) {
            return {0,0};
        }
        if (root->left == NULL && root->right == NULL) {
            res += 1;
            return {root->val,1};
        }
        pair<int, int> lsum = dfs(root->left, res);
        pair<int, int> rsum = dfs(root->right, res);
        int param = (lsum.first + rsum.first + root->val) /
                    (lsum.second + rsum.second + 1);
        if (param == root->val) {
            res += 1;
        }
        pair<int, int> ans;
        ans.first = lsum.first + rsum.first + root->val;
        ans.second = lsum.second + rsum.second + 1;
        return ans;
    }
    int averageOfSubtree(TreeNode* root) {
        int res = 0;
        pair<int, int> val = dfs(root, res);
        return res;
    }
};