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
    int amountOfTime(TreeNode* root, int start) {
        queue<TreeNode*> q;
        TreeNode* st;

        unordered_map<TreeNode*, TreeNode*> m;
        q.push(root);
        if (root->val == start) st = root;

        while (!q.empty()) {
            TreeNode* c = q.front();
            q.pop();
            if (c->val == start) st = c;


            if (c->left) {
                q.push(c->left);
                m[c->left] = c;
            }

            if (c->right) {
                q.push(c->right);
                m[c->right] = c;
            }
        }

        q.push(st);
        unordered_map<TreeNode*, bool> vis;
        int t = -1;

        while (!q.empty()) {
            int s = q.size();

            for (int i = 0; i < s; i++) {
                TreeNode* c = q.front();
                q.pop();
                vis[c] = true;

                if (c->left && !vis[c->left]) {
                    q.push(c->left);
                }

                if (c->right && !vis[c->right]) {
                    q.push(c->right);
                }

                if (m[c] && !vis[m[c]]) {
                    q.push(m[c]);
                }
            }

            t++;
        } 

        return t;
    }
};