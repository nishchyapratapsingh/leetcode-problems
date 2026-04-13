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
private:
    TreeNode* first;
    TreeNode* second;
    TreeNode* lastElem;

    void morrisInorder(TreeNode* root) {
        while (root) {
            if (!root->left) {
                if (!first && lastElem->val > root->val) {
                    first = lastElem;
                    second = root;
                }
                else if (lastElem->val > root->val) {
                    second = root;
                }
                lastElem = root;
                root = root->right;
            }
            else {
                TreeNode* prev = root->left;
                while (prev->right && prev->right != root) {
                    prev = prev->right;
                }
                if (!prev->right) {
                    prev->right = root;
                    root = root->left;
                }
                else {
                    prev->right = nullptr;
                    if (!first && lastElem->val > root->val) {
                        first = lastElem;
                        second = root;
                    }
                    else if (lastElem->val > root->val) {
                        second = root;
                    }
                    lastElem = root;
                    root = root->right;
                }
            }
        }
    }
public:
    void recoverTree(TreeNode* root) {
        first = second = nullptr;
        lastElem = new TreeNode(INT_MIN);
        morrisInorder(root);
        swap(first->val, second->val);
    }
};