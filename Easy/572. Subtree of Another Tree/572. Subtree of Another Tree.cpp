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
    bool sameSubtree(TreeNode*p, TreeNode* q){
        if (!p && !q)
            return true ;
        if (!p || !q || p->val!=q->val)
            return false ;
        return true && sameSubtree(p->left, q->left) && sameSubtree(p->right, q->right) ;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root)
            return false ;
        return sameSubtree(root, subRoot) || isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot) ; 
    }
};