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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* LeftNode = list1;
        ListNode* RightNode = list1;
        for(int i =0;i<b;i++){
            RightNode = RightNode->next;
        }
        while(a-1){
            if(LeftNode->next){
                LeftNode = LeftNode->next;
            }
            else{
                break;
            }
            a--;
        }
        LeftNode->next = NULL;
        ListNode* temp = list2;
        while(temp->next!=NULL){
            temp= temp->next;
        }
        if(list2!=NULL){
            LeftNode->next =list2;
        }
        temp->next =RightNode->next;
        return list1;

    }
};