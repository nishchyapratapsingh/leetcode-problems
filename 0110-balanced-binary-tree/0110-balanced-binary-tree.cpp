class Solution {
public:
    
    int check(TreeNode* node) {
        if (!node) return 0;
        int leftHeight = check(node->left);
        if (leftHeight == -1) return -1;
        int rightHeight = check(node->right);
        if (rightHeight == -1) return -1;
        if (abs(leftHeight - rightHeight) > 1) return -1;
        return max(leftHeight, rightHeight) + 1;
    }

    bool isBalanced(TreeNode* root) {
        return check(root) != -1;
    }
};
