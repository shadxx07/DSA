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
    ListNode* doubleIt(ListNode* head) {
        ListNode* newNode = new ListNode(-1);
        ListNode* var = newNode;
        ListNode* prev = NULL;
        ListNode* temp = head;
        ListNode* front;
        while(temp!=NULL){
            front = temp->next;
            temp->next = prev;
            prev= temp;
            temp = front;
        }
        int carry = 0;
        while(prev!=NULL){
            int val = 2 * prev->val + carry;

            int digit = val % 10;
            carry = val / 10;

            ListNode* curr = new ListNode(digit);
            var->next = curr;
            var = var->next;

            prev = prev->next; 
        }
        if (carry > 0) {
            var->next = new ListNode(carry);
            var = var->next;
        }
        ListNode* current = newNode->next;
        ListNode* prevNode = NULL;
        while (current != NULL) {
    ListNode* nextNode = current->next;
    current->next = prevNode;
    prevNode = current;
    current = nextNode;
}

return prevNode;


    }
};