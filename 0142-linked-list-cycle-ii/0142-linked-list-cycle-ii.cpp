/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;

        ListNode* fast = head;
        bool isloop= false;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                isloop = true;
                break;
            }
        }
        if(!isloop){
            return NULL;
        }
        slow= head;
        while(slow!=fast){
            slow= slow->next;
            fast = fast->next;
        }
        return slow;
        
    }
};