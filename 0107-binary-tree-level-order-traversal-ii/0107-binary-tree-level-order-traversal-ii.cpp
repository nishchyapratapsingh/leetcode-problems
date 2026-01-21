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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> Traversal;
        if (root == nullptr) return Traversal;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> curr;
            for (int i=0; i<size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left!=NULL) q.push(node->left);
                if (node->right!=NULL) q.push(node->right);
                curr.push_back(node->val);
            }
            Traversal.push_back(curr);
        }
        reverse(Traversal.begin(), Traversal.end());
        return Traversal;
    }
};