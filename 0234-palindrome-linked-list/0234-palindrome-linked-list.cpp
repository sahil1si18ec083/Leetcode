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
    ListNode* findMiddle(ListNode* head){
        ListNode* prev = NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        return prev;
    }
    ListNode* reverse(ListNode* head){
        if(head==NULL || head->next==NULL) return head;
        ListNode* prev = NULL;
        ListNode* current = head;
        while(current!=NULL){
            ListNode* temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {

        if(head==NULL || head->next ==NULL) return true;

        ListNode* middle = findMiddle(head);

        ListNode* middlenext = middle->next;
   
        middle->next = NULL;
             ListNode* secondpart = reverse(middlenext);

        while(head!=NULL){
           
            
            if(head->val != secondpart->val ){
                return false;
            }
            head = head->next;
            secondpart= secondpart->next;
        }

        return true;
    }
};