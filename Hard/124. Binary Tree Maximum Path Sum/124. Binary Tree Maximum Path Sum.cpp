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
    int maxPath(TreeNode* root, int &m) {
        if (!root)
            return 0;
        int left = maxPath(root->left, m);
        int right = maxPath(root->right, m);
        m = max(m, max(0, left) + max(0, right) + root->val);
        return max(max(0, left), right) + root->val;
    }

    int maxPathSum(TreeNode* root) {
        int max_val = INT_MIN ;
        maxPath(root, max_val) ;
        return max_val ;
    }
};