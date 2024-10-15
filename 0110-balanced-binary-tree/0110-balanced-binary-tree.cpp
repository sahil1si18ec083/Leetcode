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
    int finheight(TreeNode *root, bool &flag){
        if(root==NULL){
            return 0;
        }
        if(abs(finheight(root->left,flag)- finheight(root->right,flag))>1){
            
            flag = false;
            return 123345;
        }
        return (1+max(finheight(root->left,flag), finheight(root->right,flag)) );
    }
    bool isBalanced(TreeNode* root) {

        if(root==NULL){
            return true;
        }
        bool flag = true;
        int h = finheight(root,flag);
        return flag;
    }
};