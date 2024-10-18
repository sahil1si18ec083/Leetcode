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
    void solve(TreeNode* root, vector<int>& result, int index) {
        if (root == NULL) {
            return;
        }
        // do normal pre order but do it in a way first right and then left
        if(index>=result.size()){
            result.push_back(root->val);  // pre order ka first portion
        }

        solve(root->right, result, index + 1);
        solve(root->left, result, index + 1);
    }
    vector<int> rightSideView(TreeNode* root) {

        vector<int> result;

        int index = 0;

        solve(root, result, index);

        return result;
    }
};