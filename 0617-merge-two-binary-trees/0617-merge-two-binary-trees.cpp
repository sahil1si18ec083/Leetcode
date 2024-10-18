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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        TreeNode* result = new TreeNode(0);
        if (root1 == NULL && root2 == NULL) {
            result = NULL;
            return NULL;
        }
        if (root1 == NULL) {
            result = root2;
            return root2;
        }
        if (root2 == NULL) {
            result = root1;
            return root1;
        }
        result->val = root1->val + root2->val;
        result->left = mergeTrees(root1->left, root2->left);
        result->right = mergeTrees(root1->right, root2->right);
        return result;
    }
};