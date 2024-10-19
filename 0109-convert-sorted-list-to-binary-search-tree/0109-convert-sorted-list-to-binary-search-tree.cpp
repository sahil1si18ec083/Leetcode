/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if (head==NULL){
            return NULL;
        }
        if (head->next==NULL){
            return new TreeNode(head->val);
        }
        // upar vale doo test cases tab chalage jab linkedlist break hotay hotay ek node ya null mai toot jayega
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev_slow = NULL;
        while(fast!=NULL && fast->next!=NULL){
            prev_slow= slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *slownext = slow->next;
        prev_slow->next = NULL;
        slow->next=NULL;
        TreeNode *root = new TreeNode(slow->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slownext);
        return root;
        
    }
};