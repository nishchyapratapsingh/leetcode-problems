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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 1});
        int maxi = 1;

        while (!q.empty()) {
            int size = q.size();
            long long first = q.front().second;
            long long last = 0;

            for (int i = 0; i < size; i++)
            {
                auto temp = q.front();
                q.pop();

                TreeNode* node = temp.first;
                long long idx = temp.second;
                idx-=first;

                if (i == size-1) last = idx;

                if (node->left) {
                    q.push({node->left, 2*idx});
                }
                if (node->right) {
                    q.push({node->right, 2*idx+1});
                }
            }

            maxi = max(maxi, (int)last+1);
        }

        return maxi;
    }
};