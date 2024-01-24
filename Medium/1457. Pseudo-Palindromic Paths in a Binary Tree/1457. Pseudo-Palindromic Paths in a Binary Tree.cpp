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
    int result = 0;
    void dfs(TreeNode* root, unordered_map<int,int>t){
        if (!root){
            int sum =0, length = 0 ;
            for (int i = 0; i<10;i++){
                if (t[i]%2 !=0)
                    sum++ ;
                if (t[i] != 0)
                    length+=t[i] ;
            }
            if (length!=0 &&( (length%2 == 0 && sum == 0) || (sum == 1 && length%2 !=0))){
                result++ ;
            }
            return ;
        }
        t[root->val]++ ;
        dfs(root->left, t) ;
        dfs(root->right, t) ;
        t[root->val]--;
        return ;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int, int>t ;
        dfs(root, t) ;
        return result; 
    }
};