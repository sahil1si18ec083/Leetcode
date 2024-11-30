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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* oddDummyNode = new ListNode(-1);
        ListNode* evenDummyNode = new ListNode(-1);
        ListNode* current = head;
        ListNode* currentOdd = oddDummyNode;
        ListNode* currenteven = evenDummyNode;
        int index=1;
        while (current != NULL) {
            if (index % 2 == 1) {
                currentOdd->next = current;
                currentOdd = currentOdd->next;

            } else {
                currenteven->next = current;
                currenteven = currenteven->next;
            }
            current = current->next;
            index++;
        }
        currentOdd->next = evenDummyNode->next;
        currenteven->next = NULL;
        return oddDummyNode->next;
    }
};