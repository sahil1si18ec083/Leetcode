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
    int helper(TreeNode* root, int& maxpossiblesum) {
        if (root == NULL) {
            return 0;
        }
        int leftsum = helper(root->left, maxpossiblesum);
        int rightsum = helper(root->right, maxpossiblesum);
        if(leftsum<0){
            leftsum=0;
        }
        if(rightsum<0){
            rightsum=0;
        }
       

        maxpossiblesum = max(maxpossiblesum, leftsum + rightsum + root->val);
        return (max(leftsum,rightsum)+root->val);
    }
    int maxPathSum(TreeNode* root) {
        int maxpossiblesum = INT_MIN;
        int sum = helper(root, maxpossiblesum);
        return maxpossiblesum;
    }
};