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
    void dfs(TreeNode* root, vector<int>& path, vector<vector<int>>& result,
             int sum, int targetSum) {
        if (root == NULL)
            return;
        path.push_back(root->val);
        if (root->left==NULL && root->right==NULL && sum + root->val == targetSum) {
            result.push_back(path);
        }

        dfs(root->left, path, result, sum + root->val, targetSum);
        dfs(root->right, path, result, sum + root->val, targetSum);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        int sum = 0;

        vector<int> path;

        vector<vector<int>> result;

        dfs(root, path, result, sum, targetSum);

        return result;
    }
};