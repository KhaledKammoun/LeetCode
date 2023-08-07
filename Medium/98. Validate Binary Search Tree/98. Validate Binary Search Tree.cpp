class Solution {
public:
    bool validTree(TreeNode* root, TreeNode*& var) {
        if (!root) {
            return true;
        }
        if (!validTree(root->left, var)) {
            return false;
        }
        if (var && root->val <= var->val) {
            return false;
        }
        var = root;
        return validTree(root->right, var);
    }

    bool isValidBST(TreeNode* root) {
        TreeNode* var = nullptr;
        return validTree(root, var);
    }
};
