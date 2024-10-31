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
    bool isleaf(TreeNode* root) {
        if (root->left == NULL && root->right == NULL) {
            return true;
        }
        return false;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (root == NULL) {
            return root;
        }
        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);
        if (root->left && isleaf(root->left) && root->left->val == target) {
            root->left = NULL;
        }

        if (root->right && isleaf(root->right) && root->right->val == target) {
            root->right = NULL;
        }
        if (isleaf(root) && root->val == target) {
            return NULL;
        }
        return root;
    }
};