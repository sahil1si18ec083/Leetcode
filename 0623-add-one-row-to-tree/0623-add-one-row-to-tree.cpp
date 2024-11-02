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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
         if(depth==1){
            TreeNode* newroot = new TreeNode(val);
            newroot->left= root;
            return newroot;
         }
         bool rowadded= false;
        int currentdepth = 1;
        queue<TreeNode*> q;
        q.push(root);
       

        while (q.size() > 0 && !rowadded) {
            int qsize = q.size();

            for (int i = 0; i < qsize; i++) {
                TreeNode* temp = q.front();
                q.pop();
                if (currentdepth == depth - 1) {
                    TreeNode* leftNode = temp->left == NULL ? NULL : temp->left;
                    TreeNode* rightNode =
                        temp->right == NULL ? NULL : temp->right;
                    TreeNode* first = new TreeNode(val);
                    TreeNode* second = new TreeNode(val);
                    temp->left = first;
                    temp->right = second;
                    first->left = leftNode;
                    second->right = rightNode;
                    rowadded= true;
                } else {
                    if (temp->left) {
                        q.push(temp->left);
                    }
                    if (temp->right) {
                        q.push(temp->right);
                    }
                }
            }

            currentdepth++;
        }
        return root;
    }
};