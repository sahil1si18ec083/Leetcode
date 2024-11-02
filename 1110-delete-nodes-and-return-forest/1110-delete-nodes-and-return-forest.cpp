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
    TreeNode* helper(TreeNode* &root, set<int> &st, vector<TreeNode*>& res) {

        if(root==NULL){
            return NULL;
        }
        root->left = helper(root->left,st, res);
        root->right = helper(root->right, st,res);
        if(st.find(root->val)!=st.end()){
            if(root->left==NULL  && root->right==NULL){
                return NULL;
            }
            if(root->left && !root->right){
                res.push_back(root->left);
                return NULL;
            }
             if(root->right && !root->left){
                res.push_back(root->right);
                return NULL;
            }
            if(root->left && root->right){
                res.push_back(root->left);
                res.push_back(root->right);
                return NULL;
            }
        }
        return root;

    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> res;
        set<int> st;
        for(int i=0;i< to_delete.size();i++){
            st.insert( to_delete[i]);
        }
        TreeNode* finalTree = helper(root, st, res);
        cout<<root->val;
        if(st.find(root->val)==st.end()){
            res.push_back(root);
        }
        return res;
    }
};