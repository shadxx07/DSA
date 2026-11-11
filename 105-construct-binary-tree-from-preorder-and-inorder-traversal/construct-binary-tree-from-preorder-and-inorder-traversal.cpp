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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,
                    int& index, int start, int end) {

        if(start > end) return NULL;

        int element = preorder[index];
        index++;

        TreeNode* root = new TreeNode(element);

        int pos = start;

        while(inorder[pos] != element) {
            pos++;
        }

        root->left = build(preorder, inorder, index, start, pos - 1);

        root->right = build(preorder, inorder, index, pos + 1, end);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;

        return build(preorder, inorder, index, 0, inorder.size() - 1);
    }
};