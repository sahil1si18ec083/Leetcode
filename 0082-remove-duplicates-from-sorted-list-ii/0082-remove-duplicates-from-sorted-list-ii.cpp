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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* slow = dummy;
        ListNode* fast = head;
        ListNode* prev = NULL;
        while (fast ) {
             ListNode* next = fast->next;

            if((prev==NULL || prev->val !=fast->val) && (next==NULL || next->val !=fast->val)){
                slow->next = fast;
               
                slow= slow->next;
                
            }
           
                prev= fast;
                fast= fast->next;
            
        }
        slow->next = NULL;

        return dummy->next;
    }
};