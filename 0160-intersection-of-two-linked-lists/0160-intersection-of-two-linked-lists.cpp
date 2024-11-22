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
        if (headA == NULL || headB == NULL) {
            return NULL;
        }
        ListNode* currentA = headA;
        ListNode* currentB = headB;
        while (currentA && currentB) {
            if (currentA == currentB) {
                return currentB;
            }
            currentA = currentA->next;
            currentB = currentB->next;
            if (currentA == NULL && currentB==NULL){
                return NULL;
            }
            else if (currentA == NULL) {
                currentA = headB;
            }
            else if (currentB == NULL) {
                currentB = headA;
            }
        }
        return NULL;
    }
};