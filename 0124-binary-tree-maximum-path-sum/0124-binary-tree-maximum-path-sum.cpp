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
    int helper(TreeNode* root, int& maxsum) {
        if (root==NULL) return 0;

        int left = max(0, helper(root->left, maxsum));
        int right = max(0, helper(root->right, maxsum));

        int currsum = root->val + left+right;
        maxsum = max(currsum, maxsum);
        return (max(left, right)+root->val);    
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxsum=INT_MIN;
        helper(root, maxsum);
        return maxsum;
    }
};