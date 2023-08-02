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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result ;
        queue<TreeNode*> q ;
        q.push(root) ;
        while(!q.empty()){
            vector<int>subResult ;
            int lenRes = q.size() ;
            
            for(int i = 0; i<lenRes ; i++){
                TreeNode* current = q.front();

                if (current){
                 subResult.push_back(current->val) ;
                 q.push(current->left) ;
                 q.push(current->right) ;
                }
                q.pop() ;
            }
            if (subResult.size()!=0)
                result.push_back(subResult) ;
        }
        return result ;
    }
};