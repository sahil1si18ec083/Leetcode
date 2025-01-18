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
    int Length(ListNode* head) {
        int l = 0;
        while (head) {
            l++;
            head = head->next;
        }
        return l;
    }
    ListNode* reverse(ListNode* head) {
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(Length(head)<k){
            return head;
        }
        ListNode* newhead = head;
        for(int i=1;i<=k-1;i++){
            newhead= newhead->next;
        }
        ListNode* next = newhead;
        next = newhead->next;
        newhead->next = NULL;
        ListNode* rerversed = reverse(head);
        head->next = reverseKGroup(next,k);
        return newhead;
    }
};