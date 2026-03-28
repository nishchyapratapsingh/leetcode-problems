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
    TreeNode* f(int pres, int pree, int ins, int ine, vector<int> &preorder, vector<int> &inorder, unordered_map<int, int> &map) {
        if (pree < pres || ine < ins) {
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[pres]);
        int inroot = map[preorder[pres]];
        int cnt = inroot - ins;

        root->left = f(pres+1, pres+cnt, ins, inroot - 1, preorder, inorder, map);
        root->right = f(pres + cnt + 1, pree, inroot+1, ine, preorder, inorder, map);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> map;
        int n = inorder.size();
        for (int i = 0; i < n; i++) {
            map[inorder[i]] = i;
        }

        return f(0, n-1, 0, n-1, preorder, inorder, map);
    }

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder = preorder;
        sort(inorder.begin(), inorder.end());

        return buildTree(preorder, inorder);

    }
};