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
    pair<int, int> dfs(TreeNode* root, int& maxpathsize) {
        if (root == NULL) {
            return {INT_MIN, 0};
        }
        if (root->left == NULL && root->right == NULL) {
            maxpathsize = max(1, maxpathsize);
            return {root->val, 1};
        }
        pair<int, int> left = dfs(root->left, maxpathsize);
        pair<int, int> right = dfs(root->right, maxpathsize);
        if (root->val == left.first && root->val == right.first) {
            maxpathsize =
                max((left.second+ right.second+ 1), maxpathsize);
            return {root->val, (max(left.second, right.second)+1 )};

        } else if (root->val == left.first) {
            maxpathsize = max((left.second + 1), maxpathsize);
            return {root->val, left.second + 1};

        } else if (root->val == right.first) {
            // cout<<root->val<<"#"<<endl;
            // cout<<right.second<<","<<endl;
            // cout<<maxpathsize<<"p"<<endl;
            maxpathsize = max((right.second + 1), maxpathsize);
            // cout<<maxpathsize<<"p"<<endl;
            return {root->val, right.second + 1};
        } else {
            return {root->val, 1};
        }
    }
    int longestUnivaluePath(TreeNode* root) {
        int maxpathsize = 0;
        if(root==NULL) return 0;

        pair<int, int> res = dfs(root, maxpathsize);

        return maxpathsize-1;
    }
};