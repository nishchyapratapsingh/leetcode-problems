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
    int maxDepth(TreeNode* root) {
        stack<pair<TreeNode*, int>> st;
        if (!root) return 0;
        int maxd = 0;
        st.push({root, 1});


        while (!st.empty()) {
            auto[node, depth] = st.top();
            st.pop();
            maxd = max(maxd, depth);
            if (node->left!=NULL) {
                st.push({node->left, depth+1});
            }
            if (node->right!=NULL) {
                st.push({node->right, depth+1});
            }
            
        }
        return maxd;
    }
};