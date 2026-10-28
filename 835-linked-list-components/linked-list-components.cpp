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
    int numComponents(ListNode* head, vector<int>& nums) {
        ListNode* temp = head;
        int cnt =0;
        unordered_map<int,int>mpp;
        for(int i = 0;i<nums.size();i++){
            mpp[nums[i]] =1;
        }
        while(temp!=NULL){
            if(mpp[temp->val] ==1){
                cnt++;
                while(temp!=NULL && mpp[temp->val] ==1){
                    temp = temp->next;
                }
            }
            else{
                temp= temp->next;
            }
        }
        return cnt;
    }
};