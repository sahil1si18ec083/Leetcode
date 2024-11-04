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
        if (root == NULL)
            return 0;
        long long int maxwidth = 0;
        queue<pair<TreeNode*, long long int>> q;
        q.push({root, 0});
        while (q.size() > 0) {
            int qsize = q.size();
            int l = 0;
            int r = 0;

            for (long long int i = 0; i < qsize; i++) {

                pair<TreeNode*, long long int> temp = q.front();
                q.pop();
                if (i == 0) {
                    l = temp.second;
                }
                if (i == qsize - 1) {
                    r = temp.second;
                }
                if (temp.first->left != NULL) {
                    q.push({temp.first->left, 2 * (temp.second - l) + 1});
                }
                if (temp.first->right != NULL) {
                    q.push({temp.first->right, 2 * (temp.second - l) + 2});
                }
            }
            if (r - l + 1 > maxwidth) {
                maxwidth = r - l + 1;
            }
        }
        return maxwidth;
    }
};