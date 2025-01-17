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
    ListNode* findMiddle(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;
        while (fast && fast->next ) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
       
        return prev;
    }
    ListNode* reverse(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* prev = NULL;
        ListNode* current = head;
        while (current) {
            ListNode* temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
        }
        
        return prev;
    }
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return;
        }
        ListNode* middle = findMiddle(head);
        ListNode* middlenext = middle->next;
        middle->next = NULL;
        ListNode* middlenextreverse = reverse(middlenext);

        ListNode* dummy = new ListNode(-1);
        ListNode* current = dummy;

        while(head && middlenextreverse){
            current->next = head;
            current = current->next;
            head = head->next;
            current->next = middlenextreverse;
            current = current->next;
            middlenextreverse= middlenextreverse->next;

        }
        if(head){
            current->next = head;
            current = current->next;
        }
         if(middlenextreverse){
            current->next = middlenextreverse;
            current = current->next;
        }
        current->next = NULL;
        head = dummy->next;
    }
};