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
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* current = head;
        while(current!=NULL){
            ListNode* temp= current->next;
            current->next = prev;
            prev= current;
            current= temp;
        }
        return prev;

    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode *fast = head;
        while(fast && fast->next && fast->next->next){
            slow= slow->next;
            fast = fast->next->next;
        }

        ListNode *midNext = slow->next;
        slow->next = NULL;
        ListNode *reversedSlow= reverse(midNext);
        while(head!=NULL && reversedSlow!=NULL){
            if (head->val!= reversedSlow->val){
                return false;
            }
            head = head->next;
            reversedSlow= reversedSlow->next;
        }

        return true;
        
    }
};