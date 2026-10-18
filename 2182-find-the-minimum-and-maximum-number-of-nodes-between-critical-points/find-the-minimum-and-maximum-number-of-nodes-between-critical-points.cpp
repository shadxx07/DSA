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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>store;
        vector<int>arr;
        vector<int>ans = {-1,-1};
        ListNode* temp = head;
        while(temp!=NULL){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        int n = arr.size();
        for(int i = 1; i <n-1;i++){
            if((arr[i-1]<arr[i] && arr[i]>arr[i+1] ) || 
                (arr[i-1]>arr[i] && arr[i]<arr[i+1])){
                store.push_back(i);
            }
        }
        int size = store.size();
        if(size<2){
            return ans;
        }
        else{
        int maxDiff = store[size-1] - store[0];
        int minDiff = INT_MAX;
        for(int i = 1;i<size;i++){
            minDiff = min(minDiff, store[i] - store[i - 1]);
        }
        ans[0]= minDiff;
        ans[1] =maxDiff;
        }
        return ans;
    }
};