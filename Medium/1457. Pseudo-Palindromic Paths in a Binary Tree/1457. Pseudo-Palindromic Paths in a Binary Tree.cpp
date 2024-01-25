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
    int dfs(TreeNode* root, unordered_map<int,int>t){
        if (!root->left && !root->right){
            t[root->val]++ ;
            int sum =0, length = 0 ;
            for (int i = 0; i<10;i++){
                if (t[i]%2 !=0)
                    sum++ ;
                if (t[i] != 0)
                    length+=t[i] ;
            }
            if ((length%2 == 0 && sum == 0) || (sum == 1 && length%2 !=0)){
                return 1 ;
            }
            return 0;
        }
        t[root->val]++ ;
        return ((root->left) ? dfs(root->left, t) : 0) + ((root->right) ? dfs(root->right, t) : 0);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int, int>t ;
        return dfs(root, t) ;
        
    }
};