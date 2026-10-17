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
    ListNode* removeNodes(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        vector<int> arr;
        stack<int> st;

        ListNode* temp = head;

        while (temp != NULL) {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        vector<int> ans;

        for (int i = arr.size() - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= arr[i]) {
                st.pop();
            }

            if (st.empty()) {
                ans.push_back(arr[i]);
            }

            st.push(arr[i]);
        }

        
        ListNode* newHead = NULL;

        for (int i = 0; i < ans.size(); i++) {
        ListNode* node = new ListNode(ans[i]);
        node->next = newHead;
        newHead = node;
    }

    return newHead;

    }
};


