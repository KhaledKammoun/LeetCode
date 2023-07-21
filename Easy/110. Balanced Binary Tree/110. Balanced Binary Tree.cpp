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
    int dfs(TreeNode* root){
        if (!root)
            return 0 ;
        return 1 + max(dfs(root->left),dfs(root->right)) ;
    }
    bool isBalanced(TreeNode* root){
        if (!root)
            return true ;
        int maxleft = dfs(root->left);
        int maxright = dfs(root->right) ;
        return isBalanced(root->left) && isBalanced(root->right) && (abs(maxleft-maxright)<=1);
    }
};