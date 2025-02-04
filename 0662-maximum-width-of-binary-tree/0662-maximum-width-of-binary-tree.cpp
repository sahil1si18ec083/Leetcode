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
        int maxwidth = 1;

        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while (q.size() > 0) {
            int qsize = q.size();
            long long int start = 0;
            long long int end = 0;
            for (int i = 0; i < qsize; i++) {
                pair<TreeNode*, int> front = q.front();
                long long int index = front.second;
                if (i == 0) {
                    start = front.second;
                }
                if (i == qsize - 1) {
                    end = front.second;
                }
                q.pop();
                if (front.first->left) {
                    q.push({front.first->left, 2 * (index - start) + 1});
                }
                if (front.first->right) {
                    q.push({front.first->right, 2 * (index - start) + 2});
                }
            }
            if (end != 0 && start != 0) {
               
                if(end - start + 1 > maxwidth ){
                    maxwidth= end - start + 1;
                }
            }
        }
        return maxwidth;
    }
};