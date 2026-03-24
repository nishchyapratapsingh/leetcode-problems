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
    TreeNode* rightMost(TreeNode* root) {
        if(!root) return root;
        TreeNode* cur = root;
        while (cur->right) {
            cur = cur->right;
        }
        return cur;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;
        if (root->val == key) {
            TreeNode* nd = root->left;
            if (!nd) {
                TreeNode* ans = root->right;
                delete root;
                return ans;
            }
            if (rightMost(nd)) rightMost(nd) ->right = root->right;
            delete root;
            return nd;
        }

        TreeNode* cur = root;
        TreeNode* prev = cur;
        while (cur && cur->val != key) {
            prev = cur;
            if (cur->val < key) {
                cur = cur->right;
            }
            else {
                cur = cur->left;
            }
        }

        if (cur) {
            if (prev->right == cur) {
                if (!cur->left) {
                    prev->right = cur->right;
                    delete cur;
                    return root;
                }
                if (!cur->right) {
                    prev->right = cur->left;
                    delete cur;
                    return root;
                }
            }
            else {
                if (!cur->left) {
                    prev->left = cur->right;
                    delete cur;
                    return root;
                }
                if (!cur->right) {
                    prev->left = cur->left;
                    delete cur;
                    return root;
                }
            }

            if (prev->left == cur) prev->left = cur->left;
            else prev->right = cur->left;
            if (rightMost(cur->left)) rightMost(cur->left)->right = cur->right;
            delete cur;
            return root;
        }

        return root;
    }
};