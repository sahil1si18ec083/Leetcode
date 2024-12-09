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
    ListNode* partition(ListNode* head, int x) {
        ListNode* firstdummy = new ListNode(-1);
        ListNode* first = firstdummy;
        ListNode* seconddummy = new ListNode(-1);
        ListNode* second = seconddummy;
        while(head){
            if(head->val<x){
                first->next = head;
                first = first->next;
            }
            else{
                second->next = head;
                second = second->next;

            }
            head = head->next;
        }
        first->next = seconddummy->next;
        second->next = NULL;
        return firstdummy->next;


    }
};