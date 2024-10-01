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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        // apply BFS
        bool flag = false;
        while (q.size() > 0) {
            int length = q.size();
            for (int i = 0; i < length; i++) {
                cout<<flag;
                TreeNode* temp = q.front();
                q.pop();
                if(temp==NULL){
                    flag = true;
                    continue;
                }
                if(flag==true){
                    return false;
                }
                
                TreeNode* left = temp->left;
                TreeNode* right = temp->right;
                q.push(left);
                q.push(right);
               
                
            }
            
        }
        return true;
    }
};