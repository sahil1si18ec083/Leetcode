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
    bool isleaf(TreeNode* root){
        if(root==NULL) return false;
        if(root->left == NULL && root->right == NULL) return true;
        return false;
    }
    TreeNode* pruneTree(TreeNode* root) {
        if (root == NULL)
            return NULL;
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if(isleaf(root) && root->val==0){
            return NULL;
        }

        // if(isleaf(root->left) && root->left->val ==0 ){
        //     root->left = NULL;
        // }
        //     if(isleaf(root->right) && root->right->val ==0 ){
        //     root->left = NULL;
        // }
        return root;
    }
};