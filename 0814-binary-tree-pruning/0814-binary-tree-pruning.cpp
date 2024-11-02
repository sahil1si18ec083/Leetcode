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
    bool isonepresent(TreeNode* root){
        if(root==NULL){
            return false;
        }
        
        return ( (root->val==1)|| isonepresent(root->left) || isonepresent(root->right));
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(root==NULL){
            return NULL;
        }
         root->left = pruneTree(root->left);
         root->right = pruneTree(root->right);
         if (root->left==NULL && root->right==NULL && root->val==0){
            return NULL;
         }

        if(!isonepresent(root->left)){
            root->left=NULL;
           
        }
         if(!isonepresent(root->right)){
            root->right = NULL;
        }
        return root;
        
    }
};