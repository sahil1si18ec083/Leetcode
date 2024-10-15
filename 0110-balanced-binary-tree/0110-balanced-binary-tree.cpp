/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int finheight(TreeNode *root){
        if(root==NULL){
            return 0;
        }
        return (1+max(finheight(root->left), finheight(root->right)) );
    }
    bool isBalanced(TreeNode* root) {

        if(root==NULL){
            return true;
        }
        int l = finheight(root->left);
        int r = finheight(root->right);
        if (abs(r-l)>1){
            return false;
        }

        return (isBalanced(root->left) && isBalanced(root->right));
    }
};