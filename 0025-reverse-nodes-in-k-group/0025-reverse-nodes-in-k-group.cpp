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
    int getLength(ListNode* head) {
        int l = 0;
        while (head) {
            l++;
            head = head->next;
        }
        return l;
    }
    ListNode* reverse(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* current = head;
        while (current->next) {
            current = current->next;
        }
        ListNode* nextpointer = head->next;
        head->next = NULL;
        ListNode* newhead = reverse(nextpointer);
        nextpointer->next = head;
        return current;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || getLength(head) < k ){
            return head;
        }
        if(getLength(head)==k){
            return reverse(head);
        }

        ListNode *current = head;

        for(int i=0;i<k-1;i++){
            current= current->next;

        }
        ListNode *temp = current->next;

        current->next = NULL;

        ListNode *newhead = reverse(head);
        ListNode *reversek = reverseKGroup(temp,k);
        head->next = reversek;

        return newhead;


    }
};