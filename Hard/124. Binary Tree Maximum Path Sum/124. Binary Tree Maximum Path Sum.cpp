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
    int maxSum(TreeNode* root, int sum,int m){
        if (!root)
            return m;
        sum+=root->val ;
        m = max(m, sum) ;
        return max(maxSum(root->left, sum, m),maxSum(root->right, sum, m)) ;
        
    }
    int max_val = INT_MIN ;
    int maxPathSum(TreeNode* root) {
        if (!root)
            return max_val ;
        int left_val = 0, right_val = 0 ;
        max_val = max(max_val, maxSum(root->left, 0, 0) + maxSum(root->right, 0, 0) + root->val) ;
        return max(maxPathSum(root->left),maxPathSum(root->right)) ;
    }
};