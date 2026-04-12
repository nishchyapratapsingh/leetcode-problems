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
    void pushLeft(TreeNode* root, stack<TreeNode*> &s1)  {
        while (root) {
            s1.push(root);
            root = root->left;
        }
    }

    void pushRight(TreeNode* root, stack<TreeNode*> &s2) {
        while (root) {
            s2.push(root);
            root = root->right;
        }
    }
public:
    int next(stack<TreeNode*> &s1) {
        TreeNode* nx = s1.top();
        s1.pop();
        if (nx->right) {
            pushLeft(nx->right, s1);
        }
        return nx->val;
    }
    int prev(stack<TreeNode*> &s2) {
        TreeNode* nx = s2.top();
        s2.pop();
        if (nx->left) {
            pushRight(nx->left, s2);
        }
        return nx->val;
    }
    
    bool findTarget(TreeNode* root, int k) {
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        pushLeft(root, s1);
        pushRight(root, s2);
        int a = next(s1);
        int b = prev(s2);

        while (a < b) {

            if (a + b == k) {
                return true;
            }
            else if (a + b < k) {
                a = next(s1);
            }
            else {
                b = prev(s2);
            }
        }

        return false;
    }
};