/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root,int k,int& store){
        if(root == NULL) return;
        k = k*10 +  root->val;

        if(root->left == NULL && root ->right == NULL){
            store+=k;
        }
        solve(root->left,k,store);
        solve(root->right,k,store);
    }
    int sumNumbers(TreeNode* root) {
        int k  = 0;
        int store = 0;
        solve(root,k,store);
        return store;
    }
};