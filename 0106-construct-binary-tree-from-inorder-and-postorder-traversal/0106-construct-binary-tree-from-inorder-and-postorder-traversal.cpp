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
    TreeNode* f(int ins, int ine, int pos, int poe, vector<int> &inorder, vector<int> &postorder, unordered_map<int, int> &mp) {
        if (poe < pos || ine < ins) {
            return NULL;
        }

        TreeNode* root = new TreeNode(postorder[poe]);
        int inroot = mp[root->val];
        int cnt = inroot - ins;

        root->left = f(ins, inroot - 1, pos, pos+cnt-1, inorder, postorder, mp);
        root->right = f(inroot+1, ine, pos+cnt, poe-1, inorder, postorder, mp);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mp;
        int n = inorder.size();
        for (int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }

        return f(0, n-1, 0, n-1, inorder, postorder, mp);
    }
};