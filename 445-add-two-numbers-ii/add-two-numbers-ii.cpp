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
    ListNode* reversell(ListNode* head){
        ListNode* temp = head;
        ListNode* prev = NULL;
        ListNode* front;
        while(temp!=NULL){
            front = temp->next;
            temp->next =prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
    ListNode* SumTwo(ListNode* head1,ListNode* head2){
        ListNode* DummyNode = new ListNode(-1);
        ListNode* curr =DummyNode;
        ListNode* temp1 = head1;
        ListNode* temp2 = head2;
        int carry = 0;
        while(temp1!=NULL || temp2!=NULL){
            int sum = carry;
            if(temp1)sum+=temp1->val;
            if(temp2)sum+=temp2->val;
            ListNode* newNode = new ListNode(sum%10);
            carry =sum/10;
            curr->next =newNode;
            curr = curr->next;
            if(temp1)  temp1 = temp1->next;
            if(temp2)  temp2 = temp2->next;
        }
        if(carry){
            ListNode* newNode = new ListNode(carry);
            curr->next = newNode;
        }
        return DummyNode->next;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 =reversell(l1);
        l2 =reversell(l2);
        ListNode* ans =SumTwo(l1,l2);
        ans =reversell(ans);
        return ans;
    }
};