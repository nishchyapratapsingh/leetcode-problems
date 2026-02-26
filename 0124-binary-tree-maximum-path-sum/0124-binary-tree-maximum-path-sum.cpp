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
    int solve(TreeNode* root, int &maxSum) {
        if (!root) {
            return 0;
        }

        int ls = max(0, solve(root->left, maxSum));
        int rs = max(0, solve(root->right, maxSum));

        int currsum = ls+rs+root->val;

        maxSum = max(currsum, maxSum);

        return root->val + max(ls, rs);
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        solve(root, maxSum);

        return maxSum;
    }
};