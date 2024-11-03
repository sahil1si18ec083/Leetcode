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
    long long int MOD = 1000000007;

    int sum(TreeNode* root, int totalsum, long long int& maxproduct) {
        if (root == NULL) {
            return 0;
        }
        long long int lsum = sum(root->left, totalsum, maxproduct) ;
        long long int rsum = sum(root->right, totalsum, maxproduct) ;
        long long int product1 = (root->val % MOD + lsum + rsum) ;
        long long int product2 = (totalsum  - product1  ) ;
        long long int totalproduct = (product1 * product2 ) ;
        maxproduct = max(maxproduct, totalproduct);
        return (root->val  + lsum + rsum) ;
    }
    int maxProduct(TreeNode* root) {
        int totalsum=0;
        long long int maxproduct = 0;
         totalsum = sum(root,totalsum,maxproduct);

        
        long long int val = sum(root, totalsum, maxproduct);
        return maxproduct % MOD;
    }
};