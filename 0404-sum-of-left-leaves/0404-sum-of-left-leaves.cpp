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
     void solve(int &sum, TreeNode* root , bool isleft){
        if (root==NULL){
            return;
        }
        if (root->left==NULL && root->right==NULL && isleft){
            sum += root->val;
        }
        solve(sum , root->left, true);
        solve(sum , root->right, false);

    }
    int sumOfLeftLeaves(TreeNode* root) {

        int sum =0;
         bool isleft = false;
         solve(sum , root, isleft);
         return sum;
        
    }
};