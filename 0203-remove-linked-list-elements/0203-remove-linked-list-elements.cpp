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
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return head;
        
        ListNode* fast = head;
        ListNode* dummyNode = new ListNode(-1);
        ListNode* slow = dummyNode;
        dummyNode->next= slow;
        
        while(fast){
            if(fast->val != val){
                slow->next = fast;
                slow= slow->next;
            }
            fast = fast->next;
        }
        slow->next= NULL;
        return dummyNode->next;
        
    }
};