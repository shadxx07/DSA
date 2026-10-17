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
    int pairSum(ListNode* head) {
        ListNode* curr = head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* temp = slow->next;
        slow->next =NULL;
        ListNode* prev = NULL;
        ListNode* front;
        while(temp!=NULL){
            front = temp->next;
            temp->next =prev;
            prev= temp;
            temp = front;
        }
        long long sum = INT_MIN;
        long long maxsum = INT_MIN;
        while(curr!=NULL || prev!=NULL){
            sum = curr->val + prev->val;
            maxsum = max(sum,maxsum);
            curr= curr->next;
            prev = prev->next;
        }
        return maxsum;
        
    }
};