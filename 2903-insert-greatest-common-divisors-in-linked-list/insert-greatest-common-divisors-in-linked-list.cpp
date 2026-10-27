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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head==NULL || head->next ==NULL)return head;
        ListNode* temp = head;
        ListNode* temp2 = head->next;
        while(temp2!=NULL){
            int x = gcd(temp->val,temp2->val);
            ListNode* newNode = new ListNode(x);
            temp->next =newNode;
            newNode->next= temp2;
            temp = temp->next->next;
            temp2 = temp2->next;
        }
        return head;
    }
};