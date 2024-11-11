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
    int widthOfBinaryTree(TreeNode* root) {
        long long maxwidth = 0;

        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0}); // pushing a  pair with
        while (q.size() > 0) {
            long long qsize = q.size();
            long long start = 0;
            long long end = 0;
            for (long long i = 0; i < qsize; i++) {
                pair<TreeNode*, long long> temp = q.front();
                q.pop();
                if (i == 0) {
                    start = temp.second;
                }
                if (i == qsize - 1) {
                    end = temp.second;
                }
                if (temp.first->left != NULL) {
                    q.push({temp.first->left, 2 * (temp.second-start) + 1});
                }
                if (temp.first->right != NULL) {
                    q.push({temp.first->right, 2 * (temp.second-start) + 2});
                }
            }
            // cout<<start<<" ";
            // cout<<end;
            // cout<<endl;
            if (end - start+1 > maxwidth) {
                maxwidth = end - start+1;
            }
        }
        return maxwidth;
    }
};