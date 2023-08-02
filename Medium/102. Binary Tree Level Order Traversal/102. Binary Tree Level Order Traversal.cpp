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
    /*DFS*/
    void vectorOrder(TreeNode* root,    vector<vector<int>> &v, int x){
        if (!root)
            return ;
        if (v.size()>x)
            v[x].push_back(root->val) ;
        else 
            v.push_back({root->val}) ;
        vectorOrder(root->left,v, x+1) ;
        vectorOrder(root->right,v, x+1) ;

    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v ;
        vectorOrder(root,v, 0) ;
        return v ;
    }
};