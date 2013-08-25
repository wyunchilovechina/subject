bool isSymmetric(TreeNode *root) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (root == NULL) {
        return true;
    }
    return isSymmetricTree(root->left, root->right);
}

bool isSymmetricTree(TreeNode *left, TreeNode *right) {
    if (left == NULL && right == NULL) {
        return true;
    } else if (left != NULL && right != NULL) {
        if (left->val == right->val) {
            return isSymmetricTree(left->left, right->right) &&
                isSymmetricTree(left->right, right->left);
        } else {
            return false;
        }
    } else {
        return false;
    }
}