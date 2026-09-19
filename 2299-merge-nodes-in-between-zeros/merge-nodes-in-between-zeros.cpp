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
    ListNode* mergeNodes(ListNode* head) {
        // ListNode* newNode =new ListNode(-1);
        // ListNode* dummy = newNode;
        vector<int>nums;
        ListNode* temp = head->next;
        int sum = 0;
        while(temp!=NULL){
            if(temp->val==0)
            {
                nums.push_back(sum);
                sum = 0;
            }
            else{
                sum+=temp->val;
            }
            temp = temp->next;
        }
        ListNode* headd = new ListNode(nums[0]);
        ListNode* mover = headd;
        for(int i =1;i<nums.size();i++){
            ListNode*tempp = new ListNode(nums[i]);
            mover->next = tempp;
            mover=tempp;
        }
        return headd;
    }
};