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
    void solve(TreeNode* root, int targetSum,vector<int>nums,vector<vector<int>>&ans){
        
        if(root == NULL) return;
        targetSum-=root->val;
        nums.push_back(root->val);
        if(root->left == NULL && root->right == NULL && targetSum ==0){
            ans.push_back(nums);
        }
        solve(root->left,targetSum,nums,ans);
        solve(root->right,targetSum,nums,ans);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>nums;
        solve(root,targetSum,nums,ans);
        return ans;
    }
};