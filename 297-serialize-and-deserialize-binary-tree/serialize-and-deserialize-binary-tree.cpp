/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Serialize: Tree -> String
    string serialize(TreeNode* root) {

        if(root == NULL) return "";

        string ans = "";
        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()) {

            TreeNode* node = q.front();
            q.pop();

            if(node == NULL) {
                ans += "#,";
            }
            else {
                ans += to_string(node->val) + ",";

                q.push(node->left);
                q.push(node->right);
            }
        }

        return ans;
    }


    // Deserialize: String -> Tree
    TreeNode* deserialize(string data) {

        if(data.size() == 0) return NULL;

        stringstream s(data);
        string str;

        getline(s, str, ',');

        TreeNode* root = new TreeNode(stoi(str));

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {

            TreeNode* node = q.front();
            q.pop();

            // Left child
            getline(s, str, ',');

            if(str == "#") {
                node->left = NULL;
            }
            else {
                TreeNode* leftNode = new TreeNode(stoi(str));

                node->left = leftNode;
                q.push(leftNode);
            }

            // Right child
            getline(s, str, ',');

            if(str == "#") {
                node->right = NULL;
            }
            else {
                TreeNode* rightNode = new TreeNode(stoi(str));

                node->right = rightNode;
                q.push(rightNode);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));