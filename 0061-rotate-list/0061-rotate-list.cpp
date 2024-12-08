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
    int length(ListNode* head){
        int l=0;
        while(head){
            head = head->next;
            l++;
        }
        return l;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        int n = length(head);
        if(head==NULL || head->next==NULL || k==0 || k%=n==0) return head;
        k = k% n;
        ListNode* prev = NULL;
        ListNode* current = head;
        for(int i=0;i<n-k;i++){
            prev = current;
            current = current->next;

        }
        ListNode* newhead = current;
        while(current && current->next){
            current = current->next;

        }
        prev->next = NULL;
        current->next = head;
        return newhead;


        
    }
};