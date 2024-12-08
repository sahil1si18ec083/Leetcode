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
    ListNode* reverse(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* prev = NULL;
        ListNode* current = head;
        while (current != NULL) {
            ListNode* temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

       
        ListNode* dummyNode = new ListNode(1);
        ListNode* current = dummyNode;
        int carry =0;
        ListNode* currentl1= l1;
        ListNode* currentl2= l2;
        cout<<currentl1->val;
        cout<<currentl2->val;
        while(currentl1 && currentl2){
            int sum = currentl1->val + currentl2->val + carry;
            if(sum>9){
                carry =1;
                sum = sum %10;
            }
            else{
                carry =0;
            }
            current->next = new ListNode(sum);
            current = current->next;
            currentl1= currentl1->next;
            currentl2= currentl2->next;

        }
        while(currentl1 ){
            int sum = currentl1->val  + carry;
            if(sum>9){
                carry =1;
                sum = sum %10;
            }
            else{
                carry =0;
            }
            current->next = new ListNode(sum);
            current = current->next;
            currentl1= currentl1->next;

        }
        while(currentl2 ){
            int sum = currentl2->val  + carry;
            if(sum>9){
                carry =1;
                sum = sum %10;
            }
            else{
                carry =0;
            }
            current->next = new ListNode(sum);
            current = current->next;
            currentl2= currentl2->next;

        }
        if(carry==1){
            current->next = new ListNode(1);
            current = current->next;
        }
        return dummyNode->next;
    }
};