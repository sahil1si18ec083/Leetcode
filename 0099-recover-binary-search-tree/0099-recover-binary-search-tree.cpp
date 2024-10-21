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
    void solve(TreeNode* root, vector<int>& inorder) {
        if (root == NULL) {
            return;
        }
        solve(root->left, inorder);
        inorder.push_back(root->val);
        solve(root->right, inorder);
    }
    void recoverBST(TreeNode* root, vector<int>& inorder, int &index) {
        if (root == NULL) {
            return;
        }
        recoverBST(root->left, inorder, index);
        root->val = inorder[index++];
        recoverBST(root->right, inorder,index);
    }
    void recoverTree(TreeNode* root) {

        vector<int> inorder;
        solve(root, inorder);
        sort(inorder.begin(), inorder.end());
        int index =0;

        recoverBST(root, inorder, index);
    }
};