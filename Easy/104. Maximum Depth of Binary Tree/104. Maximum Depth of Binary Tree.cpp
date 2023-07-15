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
    unordered_map<TreeNode*, int> m ;
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0 ;

        if (!m.count(root))
            m[root] = 1;

        if (root->left) {
            m[root->left] = 1 + m[root] ;
            maxDepth(root->left) ;
        }

        if (root->right) {
            m[root->right] = 1 + m[root] ;
            maxDepth(root->right) ;
        }

        m[root] = max(m[root], max(m[root->right], m[root->left]));

        return (m[root] > 0) ? m[root] : 1;
    }
};
