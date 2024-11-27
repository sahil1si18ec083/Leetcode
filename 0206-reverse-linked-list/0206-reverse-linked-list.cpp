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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* current = head;
        while(current->next){
            current= current->next;
        }
        ListNode* nextpointer = head->next;
        head->next = NULL;
        ListNode *newhead = reverseList(nextpointer);
        nextpointer->next = head;
        return current;

        
    }
};