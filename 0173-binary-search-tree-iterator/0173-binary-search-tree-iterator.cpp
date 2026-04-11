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
class BSTIterator {
    vector<int> inorder;
    int i;
public:
    BSTIterator(TreeNode* root) {
        i = -1;

        TreeNode* cur = root;
        while (cur) {
            if (!cur->left) {
                inorder.push_back(cur->val);
                cur = cur->right;
            }
            else {
                TreeNode* prev = cur->left;
                while (prev->right && prev->right != cur) {
                    prev = prev->right;
                }

                if (!prev->right) {
                    prev->right = cur;
                    cur = cur->left;
                }

                else {
                    prev->right = nullptr;
                    inorder.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
    }
    
    int next() {
        return inorder[++i];
    }
    
    bool hasNext() {
        return (i+1 < inorder.size());
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */