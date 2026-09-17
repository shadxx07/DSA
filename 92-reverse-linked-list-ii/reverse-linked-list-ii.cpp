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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL||head->next==NULL||left == right)return head;
        ListNode* LeftNode = head;
        ListNode* RightNode = head;
        ListNode* beforeLeft = NULL;
        ListNode* prev = NULL;
        ListNode* front;

        for(int i = 1; i < left; i++){
            beforeLeft = LeftNode;
            LeftNode = LeftNode->next;
        }

        
        while(right-1){
            if(RightNode->next){
                RightNode = RightNode->next;
            }
            else{
                break;
            }
            right--;
        }

        ListNode* Right = RightNode->next;
        RightNode->next = NULL;

        ListNode* temp = LeftNode;
        while(temp!=NULL){
            front=temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }

        if(beforeLeft!=NULL){
            beforeLeft->next = prev;
        }
        else{
            head= prev;
        }
        LeftNode->next = Right;
        return head;
    }
};