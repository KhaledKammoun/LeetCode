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
            return 0;
        sum = sum + root->val ;
        m = max(m,sum) ;
        int x = maxSum(root->left, sum,m) ;
        x = maxSum(root->right, sum,m) ;
        return sum ;
    }
    int maxVal = INT_MIN ;
    int maxPathSum(TreeNode* root) {
        if (root == nullptr)
            return 0 ;
        maxVal = max(maxVal,max(root->val,root->val + maxSum(root->left,0,root->val) + maxSum(root->right,0,root->val))) ;
        int x = maxPathSum(root->left) ;
        x = maxPathSum(root->right) ;
        return maxVal ;
        
    }
};