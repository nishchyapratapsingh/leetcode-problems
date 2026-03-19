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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node = new TreeNode(val);
        if (!root) {
            return node;
        }
        TreeNode* cur = root;
        TreeNode* prev = nullptr;
        while (cur) {
            prev = cur;
            if (cur->val < val) {
                cur = cur->right;
            }
            else {
                cur = cur->left;
            }
        }

        if (prev->val < val) {
            prev->right = node;
        }
        else {
            prev->left = node;
        }

        return root;
    }
};