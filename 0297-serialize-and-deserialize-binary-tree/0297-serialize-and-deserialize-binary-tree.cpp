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

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";
        string ans;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            
            TreeNode* node = q.front();
            q.pop();

            if (!node) {
                ans += "NULL,";
                continue;
            }

            ans += to_string(node->val);
            ans+=',';

            q.push(node->left);
            q.push(node->right);
        }

        return ans.substr(0, ans.length()-1);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return NULL;
        vector<string> arr;
        stringstream ss(data);
        string token;

        while (getline(ss, token, ',')) {
            arr.push_back(token);
        }

        int n = arr.size();

        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(stoi(arr[0]));
        q.push(root);

        int i = 1;

        while (!q.empty() && i < n) {
            TreeNode* node = q.front();
            q.pop();

            if (arr[i] != "NULL") {
                TreeNode* nd = new TreeNode(stoi(arr[i]));
                node->left = nd;
                q.push(nd);
            }
            i++;

            if (i >= n) break;

            if (arr[i] != "NULL") {
                TreeNode* nd = new TreeNode(stoi(arr[i]));
                node->right = nd;
                q.push(nd);
            }
            i++;
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));