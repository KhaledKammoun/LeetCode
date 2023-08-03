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
    vector<int> rightSideView(TreeNode* root) {
        if (!root)
            return {} ;
        vector<int>result ;
        queue<TreeNode*>q ;
        q.push(root) ;
        while (q.size()){
            result.push_back(q.front()->val) ;
            int x = q.size() ;
            for (int i = 0 ; i<x ; i++){
                TreeNode* node = q.front() ;
                if (node->right) q.push(node->right) ;
                if (node->left) q.push(node->left) ;
                q.pop() ;
            }
        }
        return result ;
    }
};