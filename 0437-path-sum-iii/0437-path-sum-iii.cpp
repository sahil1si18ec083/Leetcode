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
    void helper(TreeNode* root, int targetSum, long long int sum,
                map<long long int, long long int> mp, int& result) {
        if (root == NULL) {
            return;
        }
        sum = sum + root->val;
        if (mp.find(sum - targetSum) != mp.end()) {
            result = result + mp[sum - targetSum];
        }
        if (mp.find(sum) == mp.end()) {
            mp[sum] = 1;
        } else {
            mp[sum] = mp[sum] + 1;
        }

        helper(root->left, targetSum, sum, mp, result);
        helper(root->right, targetSum, sum, mp, result);
    }
    int pathSum(TreeNode* root, int targetSum) {
        int result = 0;
        map<long long int, long long int> mp;
        mp[0] = 1;
        long long int sum = 0;
        helper(root, targetSum, sum, mp, result);
        return result;
    }
};