int maxDepth(TreeNode *root) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (root == NULL) {
        return 0;
    } else {
        int maxLeftTreeDepth = maxDepth(root->left);
        int maxRightTreeDepth = maxDepth(root->right);
        if (maxLeftTreeDepth > maxRightTreeDepth) {
            return 1 + maxLeftTreeDepth;
        } else {
            return 1 + maxRightTreeDepth;
        }
    }
}