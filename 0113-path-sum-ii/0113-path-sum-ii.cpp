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
    void solve(TreeNode* root, int targetSum, vector<int> temp,
               vector<vector<int>>& res, int sum) {
        if (root == NULL) {
            return;
        }
        temp.push_back(root->val);
        if (root->left == NULL && root->right == NULL) {
            if (sum + root->val == targetSum) {
                res.push_back(temp);
            }
            return;
        }
        // left path explore karo
        solve(root->left, targetSum, temp, res, sum + root->val);
        // right path karo
        solve(root->right, targetSum, temp, res, sum + root->val);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        vector<vector<int>> res;
        int sum = 0;
        solve(root, targetSum, temp, res, sum);
        return res;
    }
};