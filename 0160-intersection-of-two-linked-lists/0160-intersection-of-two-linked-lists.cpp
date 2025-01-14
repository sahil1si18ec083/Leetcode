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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {

        ListNode* currentA = headA;
        ListNode* currentB = headB;
        while (currentA && currentB) {
            if (currentA == currentB) {
                return currentA;
            }
            currentA = currentA->next;
            currentB = currentB->next;
             if (currentA == NULL && currentB == NULL) {
                return NULL;
            }
            
            if (currentA == NULL) {
                currentA = headB;
            }
            if (currentB == NULL) {
                currentB = headA;
            }
        }

        return NULL;
    }
};