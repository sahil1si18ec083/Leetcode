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
    vector<int> inorderTraversal(TreeNode* root) {
        vector <int> result;

        TreeNode *current = root;
        while(current!=NULL){
            if (current->left==NULL){
                result.push_back(current->val);
                current = current->right;
            }
            else {
                // current->left null nahi hai  toh left node kay right mai dekho agar vo right node kisi ko 
                // bi point nahi hai to usko current ko point karvao
                // agar vo current ko point hai toh iska matlab traverse ho chuka , print kar do, aur right mai jao
                TreeNode *leftNode = current->left;
                while(leftNode->right!=NULL && leftNode->right!= current){
                    leftNode = leftNode->right;
                }
                if (leftNode->right==current){
                    result.push_back(current->val);
                    leftNode->right = NULL;
                    current = current->right;
                }
                else{
                    leftNode->right= current;
                    current = current->left;
                }
            }
        }

        return result;

        
    }
};