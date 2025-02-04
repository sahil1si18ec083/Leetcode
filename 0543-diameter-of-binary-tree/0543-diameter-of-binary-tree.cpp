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
    int helper(TreeNode* root, int &maxdiamter){
        if(root==NULL) return 0;
        int lh = helper(root->left,maxdiamter );
        int rh = helper(root->right,maxdiamter );
        maxdiamter= max(maxdiamter, lh+ rh);
        return (1+ max(lh,rh));
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
         int maxdiamter = 0;
        int v = helper(root, maxdiamter);
        
        return maxdiamter;
        
    }
};