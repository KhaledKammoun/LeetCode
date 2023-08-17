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
    void maxSum(TreeNode* root, int sum,int &m){
        if (!root)
            return ;
        sum+=root->val ;
        m = max(m, sum) ;
        maxSum(root->left, sum, m) ;
        maxSum(root->right, sum, m) ;
        
    }
    int max_val = INT_MIN ;
    int maxPathSum(TreeNode* root) {
        if (!root)
            return 0 ;
        int left_val = 0, right_val = 0 ;
        maxSum(root->left, 0, left_val) ;
        maxSum(root->right, 0, right_val) ;
        max_val = max(max_val, left_val + right_val + root->val) ;
        int x = maxPathSum(root->left) ;
         x = maxPathSum(root->right) ;
        return max_val ;
    }
};