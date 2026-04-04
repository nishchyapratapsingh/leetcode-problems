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
    TreeNode* f(int &i, int upperBound, vector<int> &preorder) {
        if (i == preorder.size() || preorder[i] > upperBound) {
            return NULL;
        }

        TreeNode* node = new TreeNode(preorder[i++]);

        node -> left = f(i, node->val, preorder);
        node -> right = f(i, upperBound, preorder);

        return node;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return f(i, INT_MAX, preorder);
    }
};