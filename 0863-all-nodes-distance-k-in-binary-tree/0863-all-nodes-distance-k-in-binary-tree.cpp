/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> map;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr->left) {
                q.push(curr->left);
                map[curr->left] = curr;
            }

            if (curr->right) {
                q.push(curr->right);
                map[curr->right] = curr;
            }
        }

        q.push(target);
        vector<int> ans;
        unordered_map<TreeNode*, bool> vis;

        while (!q.empty()) {
            if (k == 0) {
                while (!q.empty()) {
                    ans.push_back(q.front()->val);
                    q.pop();
                }

                return ans;
            }

            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                vis[curr] = true;

                if (curr->left && !vis[curr->left]) {
                    q.push(curr->left);
                }
                if (curr->right && !vis[curr->right]) {
                    q.push(curr->right);
                }
                if (map[curr] && !vis[map[curr]]) {
                    q.push(map[curr]);
                }
            }
            k--;
        }

        return ans;
    }
};